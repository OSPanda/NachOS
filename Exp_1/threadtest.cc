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
extern void delItemFromList(DLList *dlist, int N); 
extern void driverTest(); 

int testnum = 1; // set by main(), telling which test to enter
int threadNum = 1; // set by main(), telling number of threads
int oprNum = 1; // set by main(), telling number of elements

bool canYield = false; // controlling Yield() for different threadss
DLList *l = new DLList(); // shared double link

char*
getName(int i) {
    switch(i) {
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
DllistTest1(int which) {
    printf("Inserting items in thread %d\n", which);
    genItem2List(l, oprNum);
    currentThread->Yield();
    printf("Removing items in thread %d\n", which);
    delItemFromList(l, oprNum);
}

void
DllistTest2(int which) {
    for(int i = 0; i < oprNum; i++) {
        printf("Inserting item No.%d in thread %d\n", i + 1, which);
        genItem2List(l, 1);
    }
    printf("Removing item in thread %d\n", which);
    delItemFromList(l, oprNum);
}


void
DllistTest3(int which) {
    // segment fault, delete same element at the same time 
    printf("Inserting item in thread %d\n", which);
    genItem2List(l, oprNum);
    currentThread->Yield();
    for(int i = 0; i < oprNum; i++){
        printf("Removing item No.%d in thread %d\n", i + 1, which);
        delItemFromList(l, 1); 
    }
}

void 
DllistTest4(int which) {
    // segment fault　one is in the add the other is in delete  
    if(which % 2 == 1) {
        canYield = false;
        printf("Inserting item in thread %d\n", which); 
        genItem2List(l, oprNum);
        printf("Removing item in thread %d\n", which);
        for(int i = 0; i < oprNum - 1; i++) {
            delItemFromList(l, 1);
        }
        canYield = true;
        delItemFromList(l, 1);
    } else {
        printf("Inserting item in thread %d\n", which);
        genItem2List(l, oprNum);
        printf("Removing item in thread %d\n", which);
        delItemFromList(l, oprNum);
    }
}

void 
DllistTest5(int which) {
    canYield = false;
    printf("Inserting item NO.1 in thread %d\n", which);
    genItem2List(l, 1);
    currentThread->Yield();
    canYield = true;
    for(int i = 0; i < oprNum - 1; i++){
        printf("Inserting item No.%d in thread %d\n", i + 2, which);
        genItem2List(l, 1);
    }
    printf("Removing item in thread %d\n", which);
    delItemFromList(l, oprNum);
}

void
DllistTest6(int which) {
    if(which % 2 == 1) {
        canYield = false;
        printf("Inserting item NO.1 in thread %d\n", which);
        genItem2List(l, 1);
        currentThread->Yield();
        for(int i = 1; i < oprNum; i++){
            printf("Inserting item NO.%d in thread %d\n", i + 1, which);
            genItem2List(l, 1);
            // currentThread->Yield();
        }
        printf("Removing item in thread %d\n", which);
        delItemFromList(l, oprNum);
    } else {
        printf("Inserting item NO.1 in thread %d\n", which);
        genItem2List(l, 1);
        canYield = true;
        currentThread->Yield();
        for(int i = 1; i < oprNum; i++) {
            printf("Inserting item NO.%d in thread %d\n", i + 1, which);
            genItem2List(l, 1);
            // currentThread->Yield();
        }
        printf("Removing item in thread %d\n", which);
        delItemFromList(l, oprNum);
    }
}

void 
toDllistTest(VoidFunctionPtr func) {
    DEBUG('t', "Entering  toDllistTest\n");
    Thread *t;
    for(int i = 0; i < threadNum; i++) {
        t = new Thread(getName(i + 1));
        t->Fork(func, i + 1); 
    }
} 

//----------------------------------------------------------------------
// ThreadTest
//  Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest() {
    printf("Entering test %d\n", testnum); 
    switch(testnum) {
    case 1: // switch out of function 
        toDllistTest(DllistTest1); break;
    case 2: // insert to the empty list causing one item coving the other one  
        toDllistTest(DllistTest2); break;
    case 3: // delete item  at  one time
        toDllistTest(DllistTest3); break;
    case 4: // segmentation fault, one is in the add the other is in delete  
        toDllistTest(DllistTest4); break;
    case 5: // chain scission, sometimes it will happen 
        toDllistTest(DllistTest5); break;
    case 6: // disorder output from insert items
        toDllistTest(DllistTest6); break;
    case 7:
        driverTest(); break;
    default:
    	printf("No test specified.\n"); break;
    }
}

