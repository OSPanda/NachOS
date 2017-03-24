#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "dllist.h"

#define STU_NUM 3831

void
RandomInsertN(int N, DLList* list) {
	void* item;
	int   key;

	for (int i = 0; i < N; i++) {
		srand(time(0) + i);
		item = malloc(sizeof(int));
		*(int*)item = i;
		key = rand() % (2 * STU_NUM) - STU_NUM;
		list->SortedInsert(item, key);
		printf("Inserted %d with key %d\n", i, key);
	}
}

void
RemoveN(int N, DLList* list) {
	void* item;
	int*  key = (int*)malloc(sizeof(int));

	for (int i = N; i > 0; i--) {
		item = list->Remove(key);
		if (item != NULL) {
			printf("Removed: %d with key %d\n", *(int*)item, *key);
		} else {
			printf("Empty list. \n");
			return;
		}
	}
}

// int
// main(int argc, const char* argv[]) {
// 	int N;
// 	DLList* list = new DLList;

// 	printf("To insert how many item(s)?\n");
// 	scanf("%d", &N);
// 	RandomInsertN(N, list);

// 	printf("To remove how many item(s)?\n");
// 	scanf("%d", &N);
// 	RemoveN(N, list);

// 	return 0;
// }
