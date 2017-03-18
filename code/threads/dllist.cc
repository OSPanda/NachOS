#include "copyright.h"
#include "system.h"
#include "dllist.h"

DLLElement::DLLElement(void *itemPtr, int sortKey)	// initialize a list element
{
	item = itemPtr;
	key = sortKey;
	next = NULL;
	prev = NULL;
}

DLList::DLList()	// initialize the list
{
	first = NULL;
	last = NULL;
//	yield_pos = 0;
}

// DLList::DLList(int err_pos)
// {
// 	first = NULL;
// 	last = NULL;
// 	yield_pos = err_pos;
// }

DLList::~DLList()	// de-allocate the list
{
	DLLElement *elm = first;
	DLLElement *next;
	while(elm != NULL){
		next = elm->next;
		delete elm;
		elm = next;
	}
}

void DLList::Prepend(void *item)	// add to head of list (set key = min_key - 1)
{
	DLLElement *elm = new DLLElement(item, 0);
	if(IsEmpty()){
		first = elm;
		last = elm;
	}
	else{
		elm->key = first->key-1;
		elm->next = first;
		elm->prev = NULL;
		first->prev = elm;
		first = elm;
	}
}

void DLList::Append(void *item)	// add to tail of list (set key = max_key+1)
{
	DLLElement *elm = new DLLElement(item, 0);
	if(IsEmpty()){
		first = elm;
		last = elm;
	}
	else{
		elm->key = last->key+1;
		elm->next = NULL;
		elm->prev = last;
		last->next = elm;
		last = elm;
	}
}

void *DLList::Remove(int *keyPtr)	// remove from head of list
{
	DLLElement *element;
	if(IsEmpty())
		return NULL;
	void *retitem;
	element = first;
	*keyPtr = first->key;
	// if(yield_pos == 1){
	// 	printf("Remove error\n");
	// 	currentThread->Yield();
	// }
	retitem = element->item;
	if(first == last){
		first = NULL;
		last = NULL;
	}
	else{
		// if(yield_pos == 2){
		// 	printf("Remove error\n");
		// 	currentThread->Yield();
		// }
		first = element->next;
		first->prev = NULL;
	}
	delete element;
	return retitem;
}

bool DLList::IsEmpty()	// return true if list has no elements
{
	return((first == NULL) && (last == NULL));
}

void DLList::SortedInsert(void *item, int sortKey)	// routines to put/get items on/off lsit in order (sorted by key)
{
	DLLElement *insertItem = new DLLElement(item, sortKey);
	DLLElement *ptr = first;
	if(IsEmpty()){
		first = insertItem;
		// if(yield_pos == 3){
		// 	printf("SortedInsert error, first != last\n");
		// 	currentThread->Yield();
		// }
		last = insertItem;
	}
	else{
		for(; ptr != NULL; ptr = ptr->next)
			if(ptr->key > sortKey)	break;
		// if(yield_pos == 4){
		// 	printf("SortedInsert error, the position\n");
		// 	currentThread->Yield();
		// }
		if(ptr == NULL){
			insertItem->prev = last;
			last->next = insertItem;
			last = insertItem;
			last->next = NULL;
		}
		else if(ptr == first){
				insertItem->next = first;
				first->prev = insertItem;
				first = insertItem;
				first->prev = NULL;
			}
		else{
			ptr->prev->next = insertItem;
			insertItem->prev = ptr->prev;
			// if(yield_pos == 5){
			// 	printf("SortedInsert error, sort error\n");
			// 	currentThread->Yield();
			// }
			insertItem->next = ptr;
			ptr->prev = insertItem;
		}
	}
}

void *DLList::SortedRemove(int sortKey)	// remove first item with key==sortKey
{										// 	return NULL if no such item exists
	DLLElement *ptr = first;
	if(IsEmpty()){
		return NULL;
	}
	for(; ptr != NULL; ptr = ptr->next)
		if(ptr->key > sortKey) break;
	if(ptr == NULL)
		return NULL;
	else if(ptr == first){
		first = first->next;
		first->prev = NULL;
	}
	else if(ptr == last){
		last = last->prev;
		last->next = NULL;
	}
	else{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	return ptr->item;
}

