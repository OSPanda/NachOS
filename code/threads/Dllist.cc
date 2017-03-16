#include "Dllist.h"
#include <iostream>
// #include "system.h"
using namespace std;
DLLElement::DLLElement( void *itemPtr, int sortKey )
{
    key = sortKey;
    item = itemPtr;
    next =NULL;
    prev =NULL;
}

DLList::DLList()
{
    first = NULL;
    last = NULL;
}

DLList::~DLList()
{
    DLLElement * now= first;
    DLLElement * next ;
    while(now != NULL){
        next = now->next;
        delete now;
        now =  next ;
    }
}

//add to end of list
void DLList::Append(void *item)
{
   if(!IsEmpty())
   {
       DLLElement* now = new DLLElement(item ,last->key+1);
       last->next = now;
       now->prev = last;
       last = now ;
   }else{
       DLLElement * now = new DLLElement(item,0);//default is 0
       first = last =  now ;
   }

}

void DLList::Prepend(void *item)
{
    if(!IsEmpty())
    {
        DLLElement * now = new DLLElement(item, first->key -1 );
        first->prev = now ;
        now->next = first;
        first = now ;
    }else{
        DLLElement * now = new DLLElement(item , 0);//default is 0
        first = last  = now;
    }
}

void * DLList::Remove(int *keyPtr)
{
    if(IsEmpty())
    {
        return NULL;
    }
    else
    {
        DLLElement * d = first;
        //currentThread->Yield(); 
        first = first->next;
        if(!first)
        {
            currentThread->Yield();
            first = last = NULL;
        }else
        {
            //currentThread->Yield();
            first->prev = NULL;
        }
        //currentThread->Yield();// switch to other one
        d->next = NULL;
        //currentThread->Yield();
        cout << "out: key->"<<d->key<< " value->"<< *(int *)d->item<<endl ;
        d->key = *keyPtr;
        
        return d->item;
    }
}

bool DLList::IsEmpty()
{

    if(!this->first && !this->last)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DLList::SortedInsert(void *item , int sortKey)
{
    DLLElement * newone  = new DLLElement(item,sortKey);
    //currentThread->Yield();
    if(IsEmpty())
    {  // has no one before
        //currentThread->Yield();
        first = newone;
        //currentThread->Yield();
        last = newone;
        //currentThread->Yield();
    }else{
        currentThread->Yield();
        DLLElement* now= first;
        // insert after the now
        while(now != NULL)
        {
            if(now->key <=  sortKey)
            {
                // insert to end of list
                if(now->next == NULL||now->next->key >= sortKey)
                {
                   break;
                }
                now = now->next;
            }else{
                // insert to first one
                now = NULL;
                break;
            }
        }
        DEBUG('t', "find one to delete\n");
        //currentThread->Yield();//find place to insert and swtich 

        if(now == NULL)
        { // insert to the head of list
            DEBUG('t' , "next is newone\n");
            first->prev = newone; // frist is  null
            DEBUG('t' , "next is newone"); 
            //currentThread->Yield();
            newone->next = first;
            //currentThread->Yield();
            first = newone ;
        }
        else
        {
           //currentThread->Yield();
            if(now == last)
            {//insert to the end of list
                last->next = newone;// 出错点
                //currentThread->Yield(); 
                newone->prev = last;
                //currentThread->Yield();
                last = newone ;
            }
            else
            {
                DEBUG('t' , "next is newone");
                newone -> next = now->next;
                //currentThread->Yield();
                newone->next->prev = newone;
                //currentThread->Yield();
                now->next= newone;
                //currentThread->Yield();
                newone->prev = now;
            }
        }
    }
}

void * DLList::SortedRemove(int sortKey)
{
    if(!IsEmpty())
    {
       DLLElement* now = first;
       while(now!=NULL&&now->key == sortKey)
       {
           now = now ->next;
       }
        // find  one to delete

       if(now!=NULL)
       {
          if(now == first)
          {
               first = now->next;
               if(first == NULL)
               {
                  last = NULL ;
               }else{
                   first ->prev = NULL;
               }
               now->next = NULL;

          }else if(now == last)
          {
              last = now ->prev;
              last->next = NULL;
              now ->prev = NULL;

          }else{
             now ->prev->next =  now->next;
             now -> next->prev = now->prev;

          }
          return now;
       }
    }
    return NULL;
}
