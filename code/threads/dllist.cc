#include "dllist.h"
#include <iostream>
#include "system.h"

using namespace std;

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
   if(IsEmpty()) {
       DLLElement *now = new DLLElement(item, last->key + 1);
       last->next = now;
       now->prev = last;
       last = now;
   } else {
       DLLElement *now = new DLLElement(item, 0);
       first = last = now;
   }
}

void DLList::Prepend(void *item)
{
    if(IsEmpty()) {
        DLLElement *now = new DLLElement(item, first->key - 1);
        first->prev = now;
        now->next = first;
        first = now;
    } else {
        DLLElement *now = new DLLElement(item, 0);
        first = last = now;
    }
}

void * DLList::Remove(int *keyPtr)
{
    if(!IsEmpty()) {
        return NULL;
    } else {
        DLLElement *d = first;
        first = first->next;
        if(!first) {
            first = last = NULL;
        } else {
            first->prev = NULL;
        }

        d->next = NULL;
        if(keyPtr != NULL) {
          *keyPtr = d->key;
        }
        return d->item;
    }
}

bool DLList::IsEmpty()
{
    return (!first && !last)?false:true;
}

void DLList::SortedInsert(void *item, int sortKey)
{
    DLLElement *newone = new DLLElement(item, sortKey);

    if(!IsEmpty()) {
        first = newone;
        last = newone;
    } else {
        DLLElement *now= first;
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

        if(now == NULL) {
            first->prev = newone;
            newone->next = first;
            first = newone;
        } else {
            if(now == last) {
                last->next = newone;
                newone->prev = last;
                last = newone;
            } else {
                newone->next = now->next;
                newone->next->prev = newone;
                now->next = newone;
                newone->prev = now;
            }
        }
    }
}

void * DLList::SortedRemove(int sortKey)
{
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
          return now->item;
       }
    }
    return NULL;
}
