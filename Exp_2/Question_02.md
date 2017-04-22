1. Lock的设计问题
```c
void Lock::Acquire()
{   
    IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts
    while( value == false){
        // go to sleep   does not guarantee that a thread awakened in V will get a chance
        // to run before another thread calls P
        queue->Append((void \*)currentThread);   // so go to sleep
        currentThread->Sleep();
    }
    value = false;
    currentHeldLockThread = currentThread;
    (void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}


void Lock::Release()
{
    Thread \*thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    // if queue is not empty release all blocked one
    if(!queue->IsEmpty()){//wake up one thread
        thread = (Thread \*)queue->Remove();
        if (thread != NULL)    // make thread ready
            scheduler->ReadyToRun(thread);
        value = false; // 有问题，这样会导致死锁
    }else{
        value = true;
    }
    (void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}
```
参考讲义，这样写，可能会导致其他的进程无法执行。

应改成
```c
void Lock::Release()
{
    Thread \*thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    // if queue is not empty release all blocked one
    if(!queue->IsEmpty()){//wake up one thread
        thread = (Thread \*)queue->Remove();
        if (thread != NULL)    // make thread ready
            scheduler->ReadyToRun(thread);
    }
    value = true;
    (void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}
```

2. 条件变量正确的使用情况，条件变量是锁＋队列的实现。每次使用条件变量的时候应先取得锁，并且
当使用完条件变量的时候，应该释放锁

```c
void
BoundedBuffer::Read(void \*data, int size)
{
	int \*readData = (int \*)data;
	while(size!=0){
		// learn from others on net but he's paper still have many mistakes
		// condition for buffer empty
		con_empty->Acquire();// 加锁
		while(hasCount == 0){
			not_empty->Wait(con_empty);
		}
		IntoBuffer->Acquire();
		\*readData++ = buffer[readFrom];
		// printf("get %d from buffer\n", buffer[readFrom]);
		readFrom = (readFrom + 1) % maxSize;
		hasCount--;
		IntoBuffer->Release();　

		// end of condition
		con_empty->Release();//释放锁

		// to broadcast other blocked writers
		con_full->Acquire();//must get lock
		not_full->Broadcast(con_full);
		con_full->Release();//must release lock

		size--;
		if(size % 3 == 1 && testnum == 8){
			currentThread->Yield();
		}
	}
}

```

条件变量释放锁的位置也比较特殊，需要等到hasCount改变之后才能释放锁，否则在这之前释放的话，有可能导致多个线程同时满足要求，虽然只有一个线程进入临界区，但是其他的进程在其之后进入临界区，从而导致错误。


3. 在将dllist类中设置锁的时候，本来想将锁作为dllist类的内部成员，但是后来发现加入后，在driver-list.cc的文件中导入的cstdlib类库和锁(synch.h)的头文件引入的类库有冲突，即thread.h 中相关文件和cstdlib中相关函数有冲突。最后采用了外部变量, 将锁变量作为外部变量导入dllist.cc文件中使用。




注意问题：

第四，五,六个测试，打印结果中，in表示最终完成插入，add表示开始插入,使用debug参数后发现。

./nachos -d t -q 6 -t 2 -n 2

从打印中重点关注  insert finished，in ,out ,开头的语句，发现，结果是合理的。

./nachos -d t -q 4 -t 2 -n 2

同理类似的　
