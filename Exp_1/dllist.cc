#include "dllist.h"
#include <iostream>
#include "system.h"
#include <assert.h>

using namespace std;
extern int testnum;		// introduce testnum to judeg the error type
extern int canYield;	// canYield is defined in threadtest.cc

// initialize a list element
DLLElement::DLLElement(void *itemPtr, int sortKey)
{
    key = sortKey;
    item = itemPtr;
    next = prev = NULL;
}

// initialize the list
DLList::DLList()
{
    first = last = NULL;
}

// de-allocate the list
DLList::~DLList()
{
    DLLElement *now = first;
    DLLElement *next;
    while(now != NULL) {  // from first to last one by one utill NULL
        next = now->next;
        delete now;	 // call delete to get rid of element now
        now = next;
    }
}

// add to tail of list (set key = max_key+1)
void DLList::Append(void *item)
{
   if(IsEmpty()) {  // if not empty, add now to the tail
       DLLElement *now = new DLLElement(item, last->key + 1);	// call new to allocate element now 
       last->next = now;
       now->prev = last;
       last = now;
   } else {  // if empty, now is both first and last 
       DLLElement *now = new DLLElement(item, 0);
       first = last = now;
   }
}

// add to head of list (set key = min_key-1)
void DLList::Prepend(void *item)
{
    if(IsEmpty()) {	 // if not empty, add now to the head
        DLLElement *now = new DLLElement(item, first->key - 1);
        first->prev = now;
        now->next = first;
        first = now;
    } else {  // if empty, now is both first and last 
        DLLElement *now = new DLLElement(item, 0);
        first = last = now;
    }
}

// remove from head of list
// set *keyPtr to key of the removed item
void * DLList::Remove(int *keyPtr)
{
    if(!IsEmpty()) {  // if empty, return NULL
        return NULL;
    } else {  // if not empty
        DLLElement *d = first;  // remove from head of list

        // if testnum is 3, call Yield() to cause a thread switch
        // all threads remove the first element at the same time
        if(testnum == 3) {
          currentThread->Yield();
        }

        first = first->next;

        if(!first) {  // if empty after removing first element
        	// if testnum is 4, call Yield() to cause a thread switch
        	// segmentation fault , one is adding but the other is deleting 
            if(testnum == 4 && canYield) {
                currentThread->Yield();
            }
            first = last = NULL;
        } else {  // if not empty
            if(testnum == 3) {
                DEBUG('t', "type 3, 2nd switch\n");  // debug and print the information
                currentThread->Yield();
                assert(first != NULL);
            }
            
            first->prev = NULL;
        }

        d->next = NULL;
        if(testnum == 3) {
          DEBUG('t', "type 3, 3rd switch\n"); 
          currentThread->Yield();
        }
        if(keyPtr != NULL) {
          *keyPtr = d->key;  // set *keyPtr to key of the removed item
        }
        return d->item;  // return item 
    }
}

// return true if list has elements
bool DLList::IsEmpty()
{
    return (!first && !last)?false:true;
}

// routines to put/get items on/off list in order (sorted by key)
void DLList::SortedInsert(void *item, int sortKey)
{
    static int control = 0;  // also control the switch of threads
    DLLElement *newone = new DLLElement(item, sortKey);
    if(!IsEmpty()) {  // if empty
    	// if testnum is 2, call Yield() to cause a thread switch
        // all threads judge the list to be empty
        // insert to the empty list and switching thread cause one item to cover the other one
        if(testnum == 2) {
          currentThread->Yield();
          first = newone;
          currentThread->Yield();
          last = newone;
          currentThread->Yield();
        } else {  // insert without threads switch
          first = newone;
          last = newone;
        }
    } else { // if not empty
        if(testnum == 4 && canYield) {
            currentThread->Yield();
        }

        DLLElement *now= first;
        // if testnum is 6, call Yield() to cause a thread switch
        // insert items but in disorder
        if(testnum == 6 && canYield) {
            currentThread->Yield();
            DEBUG('t', "location 1 to insert key\n", newone->key);
        }
		
		// sorted by key
        while(now != NULL) {  
            if(now->key <= sortKey) {
                if(now->next == NULL || now->next->key >= sortKey) {
                   break;
                }
                now = now->next;
            } else {
                now = NULL;
                break;
            }
        }

        if(testnum == 6 && canYield) {
            currentThread->Yield();
            DEBUG('t', "location 2 to insert key\n", newone->key);
        }

        if(now == NULL) {
              if(testnum == 4) {
                  DEBUG('t', "now is null\n");
                  assert(first != NULL);
              }
              if(testnum == 6 && canYield) {
                  currentThread->Yield();
                  DEBUG('t', "location 3 to insert key\n", newone->key);
              }

              first->prev = newone;
              newone->next = first;
              first = newone;
        } else {
            if(testnum == 6 && canYield) {
                currentThread->Yield();
                DEBUG('t', "location 4 to insert key\n", newone->key);
            }

            if(now == last) {
                last->next = newone;
                newone->prev = last;
                last = newone;
            } else {
            	// if testnum is 5, call Yield() to cause a thread switch
            	// chain scission
                if(testnum == 5 && canYield && control % 2 == 0) {
                    currentThread->Yield();
                    control++;
                }

                newone->next = now->next;
                newone->next->prev = newone;
                if(testnum == 5 && canYield && control % 2 == 1) {
                    currentThread->Yield();
                    control++;
                }
                now->next = newone;
                newone->prev = now;
            }
        }
        if(testnum == 6 && canYield) {
            currentThread->Yield();
        } 
    }
}

// remove first item with key == sortKey
void* DLList::SortedRemove(int sortKey)
{
    if(IsEmpty()) {  // if list is not empty
       DLLElement *now = first;
       while(now != NULL && now->key != sortKey) {  // find out the element with key == sortKey
           now = now->next;
       }
       if(now != NULL) {
          if(now == first) {  // the first is the required one
               first = now->next;
               if(first == NULL) {
                  last = NULL;
               } else {
                   first->prev = NULL;
               }
               now->next = NULL;
          } else if(now == last) {  // the last is the required one
              last = now->prev;
              last->next = NULL;
              now->prev = NULL;
          } else {
             now->prev->next = now->next;
             now->next->prev = now->prev;
          }
          return now->item;
       }
    }
    return NULL;  // return NULL if no such item exists
}
