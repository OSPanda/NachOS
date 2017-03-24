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
extern void genItem2List(DLList *dlist, int N);
extern void delItem2List(DLList *dlist,int N); 

// testnum is set in main.cc
int testnum = 1;
int threadNum=1;
int oprNum=1;
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
DllistTest(int  which)
{
    printf(" in thread  %d \n", which);
    genItem2List(l,oprNum);
    delItem2List(l,oprNum);
}

void
Dllist2Test(int which)
{
    //printf(" in thread  %d \n", which);
    //currentThread->Yield(); 
    printf(" in thread  %d \n", which);
    genItem2List(l,oprNum); 
    delItem2List(l,oprNum);
}


void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------
void 
ThreadTest2()
{

    DEBUG('t', "Entering ThreadTest2\n");
    for(int i=0 ;i< threadNum ;i++)
    {
        // printf("create one");
        Thread * t = new Thread(getName(i+1));
        t->Fork(DllistTest,i+1); 
    }
    // Thread * t1 = new Thread("forked thread");
    // Thread * t2 = new Thread("forked thread");
    // t1->Fork(DllistTest, 2); 
    // t2->Fork(Dllist2Test, 3);
   // DllistTest(0);
}

void
ThreadTest()
{
    printf("%d \n",testnum); 
    switch (testnum) {
    case 1:
	ThreadTest1();
	break;
    case 2:
    //add test example 添加用例
    ThreadTest2();  
    break ;
    default:
	printf("No test specified.\n");
	break;
    }
}

