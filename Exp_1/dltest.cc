// Test cases for dllist
#include "dllist.h"
#include <assert.h>
#include <cstdio>
#include <cstdlib>

int* 
intNode(int i) {
    int *place = (int*)malloc(sizeof(int));
    *place = i;
    return place;
}

void 
printDL(DLList *t) {
    int *thing = NULL, *outk = intNode(0);
    DLLElement *now = t->first;

    while(now != NULL) {
        printf("%d key %d\n", *(int*)(now->item), now->key);
        now = now->next;
    }
}


void Impl_of_IsEmpty() {
    DLList* t = new DLList();
    assert(t->IsEmpty() == 0);
    t->Prepend(NULL);
    assert(t->IsEmpty() == 1);
}

void 
Ppd_Apd_at_Head_and_Tail_on_Empty_List() {
    int i = -2, j = -2, count = 0;
    int *thing;
    DLList* t = new DLList();
    DLList* t2 = new DLList();

    t->Prepend(intNode(i++));
    t->Append(intNode(i++));
    t2->Append(intNode(i++));
    t2->Prepend(intNode(i++));
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(NULL);
        assert(*thing == j);
        j++;
        count++;
    }
    assert(count == 2);
    j = 1; count = 0;
    while(t2->IsEmpty()) {
        thing = (int*)t2->Remove(NULL);
        assert(*thing == j);
        j--;
        count++;
    }
    assert(count == 2);
}

void 
Ppd_Apd_at_Head_and_Tail_on_Not_Empty_List_with_SrtIns() {
    int i = -2, j = -2, count = 0;
    int *thing, *outk = intNode(0);
    DLList* t = new DLList();
    DLList* t2 = new DLList();

    t->SortedInsert(intNode(-1), 0);
    t->Prepend(intNode(i++));
    t->Append(intNode(++i));

    i=-2;
    t2->SortedInsert(intNode(-1), -1);
    t2->Append(intNode(i++));
    t2->Prepend(intNode(++i));

    i = -2; j = -1;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j++;
        i++;
        count++;
    }
    assert(count == 3);

    i = 0; j = -2; count = 0;
    while(t2->IsEmpty()) {
        thing = (int*)t2->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j++;
        i--;
        count++;
    }
    assert(count == 3);
}

void 
SrtIns_and_SrtRmv_with_Ppd_Apd_Rmv() {
    int i = -2, j = -5, key = -5, count = 0;
    int *thing = NULL, *outk = intNode(0);
    DLList* t = new DLList();

    for (; key < 10 ; key += 3) {
        t->SortedInsert(intNode(i++), key);
    }
    t->Prepend(intNode(90));
    t->Append(intNode(-3));

    thing = (int*)t->SortedRemove(-6);
    assert(*thing == 90);
    thing = (int*)t->SortedRemove(2);
    assert(thing == NULL);
    thing = (int*)t->SortedRemove(8);
    assert(*thing == -3);

    i = -2;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j += 3;
        i++;
        count++;
    }
    assert(count == 5);

    i = -2; count = 0;
    for (key = 12; key > -5 ; key -= 4) {
        t->SortedInsert(intNode(i++), key);
    }
    t->Prepend(intNode(1000));
    t->Append(intNode(-132));

    thing = (int*)t->SortedRemove(-5);
    assert(*thing == 1000);
    thing = (int*)t->SortedRemove(-132);
    assert(thing == NULL);
    thing = (int*)t->SortedRemove(13);
    assert(*thing == -132);
    i = 2; j = -4;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j += 4;
        i--;
        count++;
    }
    assert(count == 5);
}

void 
Single_SrtRmv() {
    int i = -2, j = -5, key = -5;
    int *thing = NULL, *outk = intNode(0);
    DLList* t = new DLList();

    t->SortedInsert(intNode(4), 4);
    thing = (int*)t->SortedRemove(4);
    assert(*thing == 4);
    t->Append(intNode(5));
    thing = (int*)t->SortedRemove(0);
    assert(*thing == 5);
    t->Prepend(intNode(6));
    thing = (int*)t->SortedRemove(0);
    assert(*thing == 6);
}


void 
Adapted_Test() {
    int *thing = NULL, *outk = intNode(0);
    DLList* t = new DLList();
    t->SortedInsert(intNode(4), 4);
    t->SortedInsert(intNode(7), 1);
    t->SortedInsert(intNode(2), 2);
    t->SortedInsert(intNode(10), 3);
    thing = (int*)t->Remove(outk);
    assert(*thing == 7); assert(*outk == 1);
    thing = (int*)t->Remove(outk);
    assert(*thing == 2); assert(*outk == 2);
    thing = (int*)t->Remove(outk);
    assert(*thing == 10); assert(*outk == 3);
    thing = (int*)t->Remove(outk);
    assert(*thing == 4); assert(*outk == 4);
}

int 
main() {

    Impl_of_IsEmpty();
    printf("Passed 1.\n");
    Ppd_Apd_at_Head_and_Tail_on_Empty_List();
    printf("Passed 2.\n");
    Ppd_Apd_at_Head_and_Tail_on_Not_Empty_List_with_SrtIns();
    printf("Passed 3.\n");
    SrtIns_and_SrtRmv_with_Ppd_Apd_Rmv();
    printf("Passed 4.\n");
    Single_SrtRmv();
    printf("Passed 5.\n");
    Adapted_Test();
    printf("Passed 6.\n");

    printf("All tests passed.\n");
    return 0;
}

