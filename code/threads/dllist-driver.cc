#include "Dllist.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void genItem2List(DLList *dlist, int N)
{
    int* item , num;
    static int random=0; 
    random ++;
    //srand(random);
    srand(unsigned(time(0))+random);
    for(int i=0;i<N;i++)
    {
        item = new int;
        *item = rand()%200;
        num = rand()%(N*10);
        cout << "in : key->" << num << " item->" << *item << endl;
        //int * item = new int ;
        dlist->SortedInsert((void *)item, num);
        //dlist->SortedInsert((void *)&(*item = rand()%100),rand()%(N*10))
    }
}


void delItem2List(DLList *dlist,int N)
{
    void * item ;
    int out = 808;
    for(int i=0;i<N;i++)
    {
        item = dlist->Remove(&out);
        if(item!=NULL)
        {
            cout << "out:  "<<*(int *)item << endl ;
        }
    }
}


/*int main()
{
    DLList* l= new DLList();
    genItem2List(l, 10);
    cout << "has insert !"<<endl ;
    delItem2List(l, 10);

    return 0;
}
*/



