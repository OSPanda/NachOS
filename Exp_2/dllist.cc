#include "dllist.h"
#include <iostream>
#include "system.h"
#include <assert.h>
#include "synch.h"

using namespace std;
extern int testnum; // introduce testnum to judeg the error type
extern int canYield; 
extern Lock* dlistLock;
// extern Condition *dlistEmpty;　// to judge list is empty
DLLElement::DLLElement(void *itemPtr, int sortKey)
{
    key = sortKey;
    item = itemPtr;
    next = prev = NULL;
}

DLList::DLList()
{
    first = last = NULL;
}

DLList::~DLList()
{
    DLLElement *now = first;
    DLLElement *next;
    while(now != NULL) {
        next = now->next;
        delete now;
        now = next;
    }
}

void DLList::Append(void *item)
{
   dlistLock->Acquire();
   if(IsEmpty()) {
       DLLElement *now = new DLLElement(item, last->key + 1);
       last->next = now;
       now->prev = last;
       last = now;
   } else {
       DLLElement *now = new DLLElement(item, 0);
       first = last = now;
   }
   dlistLock->Release();
}

void DLList::Prepend(void *item)
{   
    dlistLock->Acquire();
    if(IsEmpty()) {
        DLLElement *now = new DLLElement(item, first->key - 1);
        first->prev = now;
        now->next = first;
        first = now;
    } else {
        DLLElement *now = new DLLElement(item, 0);
        first = last = now;
    }
    dlistLock->Release();
}

void * DLList::Remove(int *keyPtr)
{
    dlistLock->Acquire();
    if(!IsEmpty()) {
        dlistLock->Release();
        return NULL;
    } else {
        DLLElement *d = first;

        if(testnum == 3){
          currentThread->Yield();
        }
        first = first->next;
        if(!first) {
            if(testnum == 4 && canYield){
                currentThread->Yield();
            }
            first = last = NULL;
        } else {
            if(testnum == 3){
                DEBUG('t' , "type 3 , 2nd switch\n"); 
                currentThread->Yield(); 
                assert(first != NULL);
            }
            
            first->prev = NULL;
        }
        
        d->next = NULL;
        if(testnum == 3){
          DEBUG('t' , "type 3 , 3rd switch\n"); 
          currentThread->Yield();
        }
        if(keyPtr != NULL) {
          *keyPtr = d->key;
        }
        dlistLock->Release();
        return d->item;
    }
}

bool DLList::IsEmpty()
{
    return (!first && !last)?false:true;
}

void DLList::SortedInsert(void *item, int sortKey)
{
    static int control = 0;// also control the switch
    dlistLock->Acquire();
    DLLElement *newone = new DLLElement(item, sortKey);
    if(!IsEmpty()) {
        if( testnum == 2){
          currentThread->Yield();
          first = newone;
          currentThread->Yield();
          last = newone;
          currentThread->Yield();
        }else{
          first = newone;
          last = newone;
        }
        if(testnum == 6 || testnum == 4 || testnum == 5){
           DEBUG('t',"insert finished %d \n",newone->key);
        }
    } else {

        if((testnum == 4 && canYield)){
            currentThread->Yield();
        }

        DLLElement *now= first;

        if( testnum == 6 && canYield){
            currentThread->Yield();
            DEBUG('t',"location 1  to insert key %d \n",newone->key);
        }

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

        if( testnum == 6 && canYield){
            currentThread->Yield();
            DEBUG('t',"location 2 to insert key %d \n",newone->key);
        }

        if(now == NULL) {
              if(testnum == 4){
                  DEBUG('t',"now is null\n");
                  assert(first != NULL);
              }
              if( testnum == 6 && canYield){
                  currentThread->Yield();
                  DEBUG('t',"location 3 to insert key\n",newone->key);
              }

              first->prev = newone;
              newone->next = first;
              first = newone;
              if(testnum == 6 || testnum == 4 || testnum == 5){
                  DEBUG('t',"insert finished %d \n",newone->key);
              }
        } else {

            if( testnum == 6 && canYield){
                currentThread->Yield();
                DEBUG('t',"location 4 to insert key %d \n",newone->key);
            }

            if(now == last) {
                last->next = newone;
                newone->prev = last;
                last = newone;
            } else {
                if(testnum == 5 && canYield && control%2 == 0){
                    currentThread->Yield();
                    control++;
                }

                newone->next = now->next;
                newone->next->prev = newone;
                if(testnum == 5 && canYield && control%2 == 1){
                    currentThread->Yield();
                    control++;
                }
                now->next = newone;
                newone->prev = now;
            }
            if(testnum == 6 || testnum == 4 || testnum == 5){
                DEBUG('t',"insert finished %d \n",newone->key);
            }
        }
        if(testnum == 6 && canYield){
          currentThread->Yield();
        } 
    }

    dlistLock->Release();
}

void * DLList::SortedRemove(int sortKey)
{
    dlistLock->Acquire();
    
    if(IsEmpty()) {
       DLLElement *now = first;
       while(now != NULL && now->key != sortKey) {
           now = now->next;
       }
       if(now != NULL) {
          if(now == first) {
               first = now->next;
               if(first == NULL) {
                  last = NULL;
               } else {
                   first->prev = NULL;
               }
               now->next = NULL;
          } else if(now == last) {
              last = now->prev;
              last->next = NULL;
              now->prev = NULL;
          } else {
             now->prev->next = now->next;
             now->next->prev = now->prev;
          }
          dlistLock->Release();
          return now->item;
       }
    }
    dlistLock->Release();
    return NULL;
}
