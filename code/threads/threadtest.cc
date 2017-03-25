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
#include <ctime>
extern void genItem2List(DLList *dlist, int N);
extern void delItem2List(DLList *dlist,int N); 

// testnum is set in main.cc
int testnum = 1;
int threadNum=1;
int oprNum=1;
bool canYield=false;
DLList* l = new DLList();// share data structure

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
    printf("add item in thread %d\n", which);
    genItem2List(l,oprNum);
    currentThread->Yield();
    printf("delete item in thread %d\n", which);
    delItem2List(l,oprNum);
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
    printf("add item in thread %d\n", which);   
    if(which%2 == 1){
        canYield = false; 
        genItem2List(l, oprNum);
        for(int i = 0; i < oprNum-1; i++){
            delItem2List(l, 1);
        }
        canYield = true;
        delItem2List(l, 1);
    }else{
        genItem2List(l, oprNum);
        delItem2List(l, oprNum);
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
    case 1:
       //switch out of function 
        toDllistTest(DllistTest1);  
        break;
    case 2:
        // insert to  the empty list causing one item coving the other one  
        toDllistTest(DllistTest2);
        break;
    case 3:
        //delete item  at  one time
        toDllistTest(DllistTest3);
    case 4:
        toDllistTest(DllistTest4);
    default:
    	printf("No test specified.\n");
    	break;
    }
}

