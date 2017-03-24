#include "dllist.h"
#include <iostream>
#include "system.h"
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

void DLList::Append(void *item)
{
   if(IsEmpty())
   {
       DLLElement* now = new DLLElement(item ,last->key+1);
       last->next = now;
       now->prev = last;
       last = now ;
   }else{
       DLLElement * now = new DLLElement(item,0);
       first = last =  now ;
   }

}

void DLList::Prepend(void *item)
{
    if(IsEmpty())
    {
        DLLElement * now = new DLLElement(item, first->key -1 );
        first->prev = now ;
        now->next = first;
        first = now ;
    }else{
        DLLElement * now = new DLLElement(item , 0);
        first = last  = now;
    }
}

void * DLList::Remove(int *keyPtr)
{
    if(!IsEmpty())
    {
        return NULL;
    }
    else
    {
        DLLElement * d = first;
        first = first->next;
        if(!first)
        { //只有一个节点的时候
            first = last = NULL;
        }else
        {
            first->prev = NULL;
        }

        d->next = NULL;

        if( keyPtr != NULL){
          *keyPtr = d->key ;
        }
        return d->item;
    }
}

bool DLList::IsEmpty()
{
    if(!this->first && !this->last)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void DLList::SortedInsert(void *item , int sortKey)
{
    DLLElement * newone  = new DLLElement(item,sortKey);

    if(!IsEmpty())
    {  //只有一个节点
        first = newone;
        last = newone;
    }else{
        DLLElement* now= first;
        // 寻找插入位置
        while(now != NULL)
        {
            if(now->key <=  sortKey)
            {

                if(now->next == NULL||now->next->key >= sortKey)
                {//到最后一个，或者找到比key值大的节点
                   break;
                }
                now = now->next;
            }else{
                // 插入第一个节点
                now = NULL;
                break;
            }
        }

        if(now == NULL)
        {// 插入 第一个节点
            first->prev = newone;
            newone->next = first;
            first = newone ;
        }
        else
        {
            if(now == last)
            {//插在最后面
                last->next = newone;
                newone->prev = last;
                last = newone ;
            }
            else
            {//一般情况插入
                newone -> next = now->next;
                newone->next->prev = newone;
                now->next= newone;
                newone->prev = now;
            }
        }
    }
}

void * DLList::SortedRemove(int sortKey)
{
    if(IsEmpty())
    {
       DLLElement* now = first;
       while(now!=NULL&&now->key != sortKey)
       {
           now = now ->next;
       }

       if(now!=NULL)
       {
          if(now == first)
          {//在第一个节点删除
               first = now->next;
               if(first == NULL)
               {//只有一个节点
                  last = NULL ;
               }else{
                   first ->prev = NULL;
               }
               now->next = NULL;

          }else if(now == last)
          {// 在最后一个节点删除
              last = now ->prev;
              last->next = NULL;
              now ->prev = NULL;

          }else{
             now ->prev->next =  now->next;
             now -> next->prev = now->prev;

          }
          return now->item;
       }
    }
    return NULL;
}
