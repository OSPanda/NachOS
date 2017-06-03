// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "dllist.h"
#include "synch.h"
#include "Table.h"
#include "BoundedBuffer.h"
#include "Elevator.h"
#include <assert.h>
extern void genItem2List(DLList *dlist, int N);
extern void delItem2List(DLList *dlist,int N); 

// testnum is set in main.cc
int testnum = 1;
int threadNum=1;
int oprNum=1;
bool canYield=false;
DLList* l = new DLList();// share data structure
Lock *outListLock =  new Lock("out of dlist define");
Lock *dlistLock = new Lock("lock of dlist"); 
Table *table = new Table(10);
BoundedBuffer *buffer = new BoundedBuffer(20);
int data[] = {1,3,4,13,12,17,18,23,19,20,13,33,27,43,26,21,16,14,10,29};
Building *building;
//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

char *
getName(int i)
{
    switch(i)
    {
        case 0: return "forked thread 0";
        case 1: return "forked thread 1"; 
        case 2: return "forked thread 2";
        case 3: return "forked thread 3"; 
        case 4: return "forked thread 4";
        case 5: return "forked thread 5"; 
        case 6: return "forked thread 6";
        case 7: return "forked thread 7"; 
        case 8: return "forked thread 8";
        case 9: return "forked thread 9"; 
        case 10: return "forked thread 10";
        default:
            return "forked thread 00";
    }
}

void
SimpleThread(int which)
{
    int num;
    for (num = 0; num < 5; num++) {
	   printf("*** thread %d looped %d times\n", which, num);
       currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
DllistTest1(int  which)
{
    outListLock->Acquire();
    printf("add item in thread %d\n", which);
    genItem2List(l,oprNum);
    currentThread->Yield();
    printf("delete item in thread %d\n", which);
    delItem2List(l,oprNum);
    outListLock->Release();

}

void
DllistTest2(int which)
{
    for(int i = 0 ; i < oprNum ; i++){
        printf("add NO.%d item in thread %d\n", i+1 ,which);
        genItem2List(l,1);
    }
    printf("delete item in thread %d\n", which);
    delItem2List(l,oprNum);
}


void
DllistTest3(int which)
{ // segmentation fault  delete  one element at one time
    printf("add item in thread %d\n", which);
    genItem2List(l,oprNum);
    currentThread->Yield();
    for(int i = 0;i < oprNum ;i++){
        printf("delete NO.%d item in thread %d\n",i+1 ,which);
        delItem2List(l,1); 
    }
}

void 
DllistTest4(int which){
    // segmentation fault　one is in the add the other is in delete  
    if(which%2 == 1){
        canYield = false;
        printf("add item in thread %d\n", which); 
        genItem2List(l, oprNum);
        printf("delete item in thread %d\n", which);
        for(int i = 0; i < oprNum-1; i++){
            delItem2List(l, 1);
        }
        canYield = true;
        delItem2List(l, 1);
    }else{
        printf("add item in thread %d\n", which);
        genItem2List(l, oprNum);
        printf("delete item in thread %d\n", which);
        delItem2List(l, oprNum);
    }

}

void 
DllistTest5(int which){
    canYield = false;
    printf("add NO.1 item in thread %d\n",which);
    genItem2List(l, 1);
    currentThread->Yield();
    canYield = true;
    for(int i = 0; i < oprNum-1; i++){
        printf("add NO.%d item in thread %d\n",i+2,which);
        genItem2List(l, 1);
    }
    printf("delete item in thread %d\n", which);
    delItem2List(l, oprNum);
}

void
DllistTest6(int which){
    if( which%2 == 1){
        canYield = false;
        printf("add NO.1 item in thread %d\n", which);
        genItem2List(l,1);
        currentThread->Yield();
        for(int i = 1 ; i < oprNum ; i++){
            printf("add NO.%d item in thread %d\n", i+1 ,which);
            genItem2List(l,1);
            // currentThread->Yield();
        }
        printf("delete item in thread %d\n", which);
        delItem2List(l,oprNum);
    }else{
        printf("add NO.1 item in thread %d\n", which);
        genItem2List(l,1);
        canYield = true;
        currentThread->Yield();
        for(int i = 1 ; i < oprNum ; i++){
            printf("add NO.%d item in thread %d\n", i+1 ,which);
            genItem2List(l,1);
            // currentThread->Yield();
        }
        printf("delete item in thread %d\n", which);
        delItem2List(l,oprNum);
    }
    
}

void
TestTable(int which)
{
    int *object = new int,index;
    *object = data[which -1];
    printf("add object %d to table in thread %d\n",*object ,which);
    index = table->Alloc((void *)object);
    if(index != -1){
        assert(((int *)table->Get(index))==object);
        printf("get object %d to table in thread %d\n",*(int *)(table->Get(index)),which);
        table->Release(index);
    }
}
 
void
TestBoundedBuffer(int which)
{
    // one is write and others is consumer the data 
    int *consume = NULL;
    if(which == 1){
        printf("produce begin in thread %d\n", which);
        buffer->Write((void *)data,18);
    }else{
        printf("comsume begin in thread %d\n", which);
        DEBUG('t',"TestBoundedBuffer before malloc\n");
        consume = new int[which-1];
        DEBUG('t',"TestBoundedBuffer after malloc\n");
        buffer->Read((void *)consume , which); 
        printf("the datas from buffer in thread %d\n",which);
        for(int i = 0; i < which-1; i++){
            printf("%d\n",consume[i]);
        }
        delete[] consume;
        printf("consumer completed in thread %d\n", which);
    }
}


void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");
    
    // Thread *t = new Thread("forked thread");
    // t->Fork(SimpleThread, 1);
    // SimpleThread(0);
}

// test alarm 
void 
testAlarm(int which)
{
    alarms->Pause(which*oprNum);
    printf("NO.%d thread finish its test\n",which);
}

//test elevator
//--------------------------
// rider action
//------------------
void rider(int id, int srcFloor, int dstFloor) {
  Elevator *e;

  if (srcFloor == dstFloor)
     return;

  DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
  do {
     if (srcFloor < dstFloor) {
        DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
        building->CallUp(srcFloor);
        DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
        e = building->AwaitUp(srcFloor);
     } else {
        DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
        building->CallDown(srcFloor);
        DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
        e = building->AwaitDown(srcFloor);
     }
     DEBUG('t', "Rider %d Enter()\n", id);
  } while (!e->Enter()); // elevator might be full!

  DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
  e->RequestFloor(dstFloor); // doesn't return until arrival
  DEBUG('t', "Rider %d Exit()\n", id);
  e->Exit();
  DEBUG('t', "Rider %d finished\n", id);
}

// elevator action
void 
elevatorAction(int id)
{
    building->RunElev(id);
}

void 
rider1(int which)
{
    alarms->Pause(which*oprNum);
    printf("No.%d 1->5 request\n",which);
    rider(which,1,5);
    printf("No.%d 1->5 reach\n",which);
}

void 
rider2(int which)
{
    alarms->Pause(which*oprNum);
    printf("No.%d 5->8 request \n",which);
    rider(which,5,8);
    printf("No.%d 5->8 reach\n",which);
}

void 
rider3(int which)
{
    alarms->Pause(which*oprNum);
    printf("No.%d 8->1 request\n",which);
    rider(which,8,1);
    printf("No.%d 8->1 reach\n",which);
}

// main thread
void 
mainThreadAction()
{
    // run elevator
    building = new Building("office buildings\n",15,1);
    Thread *elev = new Thread("thread for elevator\n");
    elev->Fork(elevatorAction,1);

    // run rider 
    Thread *r1 = new Thread("rider 1");
    r1->Fork(rider1,1); 

    Thread *r2 = new Thread("rider 1");
    r2->Fork(rider2,3); 

    Thread *r3 = new Thread("rider 1");
    r1->Fork(rider3,3); 

    alarms->Pause(20*oprNum);
    printf("all rider has reach dest and eixt\n");
}



//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------
void 
toDllistTest(VoidFunctionPtr func)
{
    DEBUG('t', "Entering  toDllistTest\n");
    Thread *t;
    for(int i=0 ;i < threadNum ;i++) {
        t = new Thread(getName(i+1));
        t->Fork(func,i+1); 
    }
} 

void
ThreadTest()
{
    printf("%d \n",testnum); 
    switch (testnum) {
    case 1: //switch out of function 
        toDllistTest(DllistTest1);  
        break;
    case 2: // insert to  the empty list causing one item coving the other one  
        toDllistTest(DllistTest2);
        break;
    case 3: //delete item  at  one time
        toDllistTest(DllistTest3);
        break;
    case 4:
        // segmentation fault , one is in the add the other is in delete  
        toDllistTest(DllistTest4);
        break;
    case 5:
        //chain scission ,sometimes it will happen 
        toDllistTest(DllistTest5);
        break;
    case 6:
        //　disorder output from insert items
        toDllistTest(DllistTest6);
        break;
    case 7:
        // to test Table.h file
        toDllistTest(TestTable);
        break;
    case 8:
        // to test BoundedBuffer.h
        toDllistTest(TestBoundedBuffer);
        break;
    case 9:
        toDllistTest(testAlarm);
        break;
    case 10:
        mainThreadAction();
        break;
    default:
    	printf("No test specified.\n");
    	break;
    }
}

