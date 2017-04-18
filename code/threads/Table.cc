#include "Table.h"
#include <assert.h>
#include <cstring>
#include "synch.h"
#include "system.h"
extern int testnum; // introduce testnum to judeg the error type
Table::Table(int size)
{
	num = size;
	left = size;
	table = new void*[size];
	memset(table,0,sizeof(void *)*size); 
	nowindex = 0;
	lock = new Lock("table lock");
}

Table::~Table()
{
	delete[] table;
	delete lock;
}

int 
Table::Alloc(void *object)
{
	lock->Acquire();
	if(testnum == 7){// to test mux
		currentThread->Yield();
	}
	if(!left){
		return -1; 
	}else{
		// find place to insert data
		while(table[nowindex]){
			nowindex = (nowindex+1) % num;
		}
		table[nowindex] = object;
		nowindex = (nowindex+1) % num;
		left--;
	}
	lock->Release();
	return nowindex-1;
}

void 
Table::Release(int index)
{
	assert(index < num && index > -1);
	lock->Acquire();
	table[index] = NULL;
	lock->Release();
}


void *
Table::Get(int index)
{
	assert(index < num && index > -1);
	lock->Acquire();
	
	if(testnum == 7){// to test mux
		currentThread->Yield();
	}
	
	void *r = table[index]; 
	lock->Release();
	return r;
}