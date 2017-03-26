#include "dllist.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define NUM_RANGE 2000

void genItem2List(DLList *list, int n)
{
    int *item, key;

    // generating new rand() seed for each iteration
    static int random = 0;
    random++;
    srand(unsigned(time(0)) + random); 
    
    for(int i=0;i<n;i++) {
        item = new int;
        *item = rand() % NUM_RANGE;
        key = NUM_RANGE / 2 - rand() % NUM_RANGE;
        cout << "Insert: key->" << key << " item->" << *item << endl;
        list->SortedInsert((void *)item, key);
    }    
}


void delItemFromList(DLList *list, int n)
{
    void *item;
    int *out = new int; // malloc mem to store the key-value

    for(int i=0;i<n;i++) {
        if(list->IsEmpty()) {
            item = list->Remove(out);
            // print removed elements to console
            if(item != NULL) {
                cout << "Remove: key->"<< *out << " item->" << *(int *)item << endl;
            } else {
                cout << "Remove: key->"<< *out << " item->NULL" << endl;
            }
        } else {
            // return when list had been emptied
            cout << "List emptied." << endl;
            return;
        }
    }
}


void driverTest()
{
    int n;
    DLList *list= new DLList();

    cout << "To insert how many items?" << endl;
    cin >> n;
    genItem2List(list, n);

    cout << "To remove how many items?" << endl;
    cin >> n;
    delItemFromList(list, n);
}




