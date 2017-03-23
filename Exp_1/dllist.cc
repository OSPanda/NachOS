// dlllist.cc
//	Impls for doublely-linked list. 
#include "dllist.h"
#include <cstdio>

DLLElement::DLLElement(void *itemPtr, int sortKey)
{
	prev = next = NULL;
	item =  itemPtr;
	key = sortKey;
}

DLList::DLList()
{
	first = last = NULL;
}

DLList::~DLList()
{
	while(IsEmpty()) {
		Remove(NULL);
	}
}

void
DLList::Prepend(void *item)
{
	DLLElement *newElem = new DLLElement(item, 0);

	if(IsEmpty()) {
		newElem->key = first->key - 1;
		first->prev = newElem;
		newElem->next = first;
		first = newElem;
	} else {
		first = last = newElem;
	}
}

void
DLList::Append(void *item)
{
	DLLElement *newElem = new DLLElement(item, 0);

	if(IsEmpty()) {
		newElem->key = last->key + 1;
		last->next = newElem;
		newElem->prev = last;
		last = newElem;
	} else {
		first = last = newElem;
	}
}

void*
DLList::Remove(int *keyPtr)
{

	void* thing = NULL;
	DLLElement *element = first;

	if(IsEmpty()) {
		if(keyPtr != NULL) {
			*keyPtr = first->key;
		}
		thing = first->item;
		first = first->next;
		if(first == NULL) {
			last = NULL;
		}
		delete element;
	}
	return thing;
}

bool
DLList::IsEmpty()
{
	return (first != NULL)?true:false;
}

void
DLList::SortedInsert(void *item, int sortKey)
{
	DLLElement *newElem = new DLLElement(item, sortKey);

	if(IsEmpty()) {
		DLLElement *nowpos = first;
		while(nowpos->key < sortKey) {
			if(nowpos->next != NULL) {
				nowpos = nowpos->next;
			} else {
				break;
			}
		}
		if(nowpos == last) {
			if(nowpos->key < sortKey) {
				newElem->prev = nowpos;
				nowpos->next = newElem;
				last = newElem;
			} else {
				newElem->prev = nowpos->prev;
				newElem->next = nowpos;
				nowpos->prev = newElem;
				if (first == nowpos) {
					first = newElem;
				}
			}
		} else if(nowpos == first) {
			newElem->next = nowpos;
			nowpos->prev = newElem;
			first = newElem;
		} else {
			newElem->next = nowpos;
			newElem->prev = nowpos->prev;
			nowpos->prev->next = newElem;
			nowpos->prev = newElem;
		}
	} else {
		first = last = newElem;
	}
}

void*
DLList::SortedRemove(int sortKey)
{
	void* thing;

	if(IsEmpty()) {
		DLLElement *nowpos = first;
		while(nowpos->key < sortKey) {
			if(nowpos->next != NULL) {
				nowpos = nowpos->next;
			} else {
				break;
			}
		}

		if(nowpos->key != sortKey) {
			return NULL;
		}

		thing = nowpos->item;
		if(nowpos == first) {
			first = first->next;
			first->prev = NULL;
			if(first == NULL) {
				last = NULL;
			}
		} else if(nowpos == last) {
			last = last->prev;
			last->next = NULL;
			if(last == NULL) {
				first = NULL;
			}
		} else {
			nowpos->prev->next = nowpos->next;
			nowpos->next->prev = nowpos->prev;
		}
		delete nowpos;
		return thing;
	} else {
		return NULL;
	}
}
