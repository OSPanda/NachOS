#include "dllist.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void genItem2List(DLList *dlist, int N)
{
    int* item , num;
    static int random=0; 
    random ++;
    srand(unsigned(time(0))+random);
    
    for(int i=0;i<N;i++){
        item = new int;
        *item = rand()%200;
        num = rand()%(N*10);
        dlist->SortedInsert((void *)item, num);
        cout << "in : key->" << num << " item->" << *item << endl;
    }    
}


void delItem2List(DLList *dlist,int N)
{
    void *item;
    int *out = new int;
    for(int i=0;i<N;i++)
    {
        item = dlist->Remove(out);
        if(item!=NULL)
        {
            cout << "out: key->"<< *out << " item->" << *(int *)item << endl ;
        }
    }
}

