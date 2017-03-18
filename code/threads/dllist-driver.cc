#include <stdlib.h>
#include <time.h>
#include "copyright.h"
#include "system.h"
#include "dllist.h"

extern void Insert(int t, int n, DLList *dllist);
extern void Remove(int t, int n, DLList *dllist);

void Insert(int t, int n, DLList *dllist)
{
	int i, ll;
	srand(time(0));
	for(i = 0; i < n; i++){
		ll = rand()%100;
		dllist->SortedInsert(NULL, ll);
		printf("Thread %d: inserted key=%d\n", t, ll);
	}
}

void Remove(int t, int n, DLList *dllist)
{
	int i, keyll;
	for(i = 0; i < n; i++){
		dllist->Remove(&keyll);
		printf("Thread %d: removed key=%d\n", t, keyll);
	}
}