#include "Alarm.h"
#include "system.h"

int Alarm::num = 0; 
Alarm::Alarm()
{
	list = new List(); 
}

Alarm::~Alarm()
{
	delete list; 
}

void 
check(int  which)
{
	//反复检查当前有几个等待闹钟的线程，若为零则结束，若不为零则切换，
	//静态变量
	while(Alarm::num != 0){
		currentThread->Yield();
	}
	DEBUG('t', "dummy thread finish\n");
	return;
}


void 
Alarm::Pause(int howLong)
{
	//use interup to make it atomicly
	IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts
	
	int when = stats->totalTicks + howLong*TimerTicks;// calculate the time to wake up  
	
	list->SortedInsert(currentThread, when); // insert into list 
	num++;

	// create dummy thread to check 
	if(num ==  1){
		Thread *t = new Thread("dummy thread\n");
		t->Fork(check,0); 
	}

	currentThread->Sleep();  // thread sleep 

	(void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}

void 
Alarm::awake()
{
	IntStatus oldLevel = interrupt->SetLevel(IntOff);   // disable interrupts

	// traverse the list ,if find time out,remove it 
	// and set thread runnable
	
	Thread *temp;
	int when,len=num;
	for(int i=0;i < len; i++)
	{
		temp = (Thread*)list->SortedRemove(&when);
		if(when <= stats->totalTicks){//time out 
			scheduler->ReadyToRun(temp);// ----------> to discuss	 
			num--;
		}else{
			// the others are postponed to now 
			list->SortedInsert(temp,when);
			break;
		}
	}

	(void) interrupt->SetLevel(oldLevel);   // re-enable interrupts
}




