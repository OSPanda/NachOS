#include "BoundedBuffer.h"
#include "synch.h"
#include "system.h"
extern int testnum; //for test buffer
BoundedBuffer::BoundedBuffer(int maxsize)
{
	IntoBuffer  = new Lock("into buffer lock");	
	// condition for buffer full
	con_full = new Lock(" buffer full ");
	con_empty = new Lock("buffer empty");
	// condition for buffer empty
	not_full = new Condition("buffer full cond");
	not_empty = new Condition("buffer empty cond");
	buffer = new int[maxsize];
	maxSize = maxsize;
	readFrom = 0; // read position 
	writeTo = 0; // write position 
	hasCount = 0;
}

BoundedBuffer::~BoundedBuffer()
{
	delete IntoBuffer;	
	delete con_full;
	delete con_empty;
	delete not_full;
	delete not_empty;
	delete[] buffer;
}

void 
BoundedBuffer::Read(void *data, int size)
{
	int *readData = (int *)data;
	while(size!=0){
		// learn from others on net but he's paper still have many mistakes
		// condition for buffer empty
		con_empty->Acquire();
		while(hasCount == 0){
			not_empty->Wait(con_empty);
		}
		IntoBuffer->Acquire();
		*readData++ = buffer[readFrom]; 
		// printf("get %d from buffer\n", buffer[readFrom]);
		readFrom = (readFrom + 1) % maxSize; 
		hasCount--;
		IntoBuffer->Release();

		// end of condition 
		con_empty->Release();

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


void 
BoundedBuffer::Write(void *data, int size)
{
	int* writeData  = (int *)data;
	while(size != 0){
		//condition for buffer full
		con_full->Acquire();
		while(hasCount == maxSize){
			not_full->Wait(con_full);
		}
		IntoBuffer->Acquire();
		buffer[writeTo] = *writeData++;
		// printf("put %d to buffer\n",buffer[writeTo]);
		writeTo = (writeTo + 1) % maxSize;
		hasCount++;
		IntoBuffer->Release();

		con_full->Release();// key pointe: must release lock
		
		// to broadcast other readers
		con_empty->Acquire();
		not_empty->Broadcast(con_empty);
		con_empty->Release();
		
		size--;
		if(size % 2 == 1 && testnum == 8){
			currentThread->Yield();
		}
	}
}







