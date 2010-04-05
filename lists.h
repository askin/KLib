/*
 * lists.h
 * Under GPL v3.0
 * Askin Yollu - askin@askin.ws
 * http://askin.ws
 */

#ifndef __LIBUTTERFLY
#define __LIBUTTERFLY
#include <stdlib.h>

// Linked list node
typedef struct llNode {
	void			*content;
	struct llNode	*previous;
	struct llNode 	*next;
} llNode;

typedef struct {
	llNode *firstElement;
	llNode *lastElement;
	int SIZE;
} LinkedList;

LinkedList *InitLinkedList(int dataSize) {
	LinkedList *llist;
	llist = malloc(sizeof(LinkedList));
	llist->SIZE = dataSize;
	llist->firstElement = NULL;
	llist->lastElement = NULL;
	return llist;
}

int AddLinkedList(LinkedList *llist, void* element) {
	llNode *tmpElement;
	
	tmpElement = malloc(sizeof(llNode));

	// can allocation?
	if(tmpElement == NULL) return 0;


	// init tmpElement
	tmpElement->content 	= element;
	tmpElement->previous 	= llist->lastElement;
	tmpElement->next 		= NULL;

	// if list is empty
	if(llist->firstElement == NULL) {
		llist->firstElement = tmpElement;
		llist->lastElement = tmpElement;
	} else {
		
		llist->lastElement->next = tmpElement;
		llist->lastElement 		 = tmpElement;
	}
	return 1;
}

int AddFirstLinkedList(LinkedList *llist, void* element) {
	llNode *tmpElement;
	tmpElement = malloc(sizeof(llNode));

	//can allocate?
	if(tmpElement == NULL) return 0;

	// init tmpElement
	tmpElement->content = element;
	tmpElement->next	= llist->firstElement;
	tmpElement->previous= NULL;

	if(llist->firstElement == NULL) { // if list is empty
		llist->firstElement = tmpElement;
		llist->lastElement	= tmpElement;
	} else {
		llist->firstElement = tmpElement;
	} // end of if else
} // end of function

// check is list empty
int LinkedListIsEmpty(LinkedList *llist) {
	if(llist->firstElement == NULL) {
		return 1;		// is empty
	} else return 0;	// is not empty
}


void* GetFirstLinkedList(LinkedList *llist) {
	return llist->firstElement->content;
}

void* GetLastLinkedList(LinkedList *llist) {
	return llist->lastElement->content;
}

int RemoveFirstLinkedList(LinkedList *llist) {
	llNode *tmpElement;
	if(llist->firstElement == NULL) return 0;

	tmpElement = llist->firstElement;
	
	if(llist->firstElement->next == NULL) {
		llist->firstElement = llist->lastElement = NULL;
	} else {
		llist->firstElement = llist->firstElement->next;
	}
	
	free(tmpElement);

	return 1;

}

int RemoveLastLinkedList(LinkedList *llist) {
  	llNode *tmpElement;
  	if(llist->firstElement == NULL) return 0;

  	tmpElement = llist->lastElement;

	if(llist->lastElement->previous == NULL) { // llist has a only 1 member
		llist->firstElement = llist->lastElement = NULL;
	} else {
		llist->lastElement = llist->lastElement->previous;
		llist->lastElement->next = NULL;
	}

	free(tmpElement);
  return 0;
}

#endif
