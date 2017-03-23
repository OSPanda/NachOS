/**
* jornshen 
* test dllist
*/ 

#include "threads/Dllist.h"
#include <iostream>
using namespace std;

int 
main(){

	DLList* list = new DLList(); 
	int data[] = {4,7,2,10};	
	int* item = data ; 
	int outKey = 404;
	void* outItem ;
	// test  SortedInsert and Remove
	list-> SortedInsert((void*)item++,4);
	list-> SortedInsert((void*)item++,1); 
	list-> SortedInsert((void*)item++,2);
	list-> SortedInsert((void*)item,3);

    cout  << list->IsEmpty() << endl; // 0 
	// aim to out: 7, 2, 10, 4,
	cout << "out:" << endl;
	for(int i=0;i<4;i++){
		outItem = list->Remove(&outKey);
		if(outItem != NULL)
		{
			cout << *(int*)outItem << endl;
		}
	}	

	

 	// test Append  and  Prepend 
	item = data; 
 	list->Append((void*)item++); 
 	list->Prepend((void*)item++);
 	list->Append((void*)item++); 
 	list->Prepend((void*)item++);

 	// out: 10,7,4,2
 	cout << "out:" << endl;
 	for(int i=0;i<4;i++){
		outItem = list->Remove(&outKey);
		if(outItem != NULL)
		{
			cout << *(int*)outItem << endl;
		}
	}


	// test SortedInsert and Append and Prepend
	item = data ;

    list-> SortedInsert((void*)item++,4); // 4 
	list-> Append((void*)item++);// key = 5 7
	list-> SortedInsert((void*)item++,3); // 2 
	list-> Prepend((void*)item); // key = 2  10
	// out: 10 2 4 7 
	cout << "out:" << endl;
    for(int i=0;i<4;i++){
		outItem = list->SortedRemove(i+2);	
		if(outItem != NULL)
		{
			cout << *(int*)outItem << endl;
		}
	}


	// test as add as delete
	// out: 4 , 7 ,2, 10

	item = data;

	list-> SortedInsert((void*)item++,4);
	cout << "out:" << endl;
	cout << *(int *)(list-> Remove(&outKey)) << endl;
	list-> SortedInsert((void*)item++,3);
	list-> Append((void*)item++);// key = 4
	cout << *(int *)(list-> SortedRemove(3)) << endl;
	cout << *(int *)(list-> Remove(&outKey)) << endl;
	list-> Prepend((void*)item); // key = 2 
	cout << *(int *)(list-> Remove(&outKey)) << endl;

	cout  << list->IsEmpty() << endl; // 1 
	return 0; 
}


/*-------------
output:
0
out:
7
2
10
4
1
out:
10
7
4
2
out:
10
2
4
7
out:
4
7
2
10
--------------*/