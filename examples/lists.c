#include <stdio.h>
#include "lists.h"

// oylesine bir sctructure
typedef struct {
	int a;
} aa;

int main( void ) {
	LinkedList *ll;
	int e;

	aa *d;
	aa *f;
	aa *g;
	aa *d1;

	d = malloc(sizeof(aa));
	f = malloc(sizeof(aa));
	g = malloc(sizeof(aa));
	d->a = 8;
	f->a = 15;
	g->a = 9;

	ll = InitLinkedList(sizeof(aa));
	e = LinkedListIsEmpty(ll);
	printf("is empty? : %d\n",e);

	AddLinkedList(ll, d);
	printf("added\n");
	e = LinkedListIsEmpty(ll);
	printf("is empty? : %d\n",e);

	d1 = GetFirstLinkedList(ll);
	printf("First %d\n", d1->a);

	d1 = GetLastLinkedList(ll);
	printf("Last %d\n", d1->a);
	printf("----------------------\n");

	AddLinkedList(ll, f);
	e = LinkedListIsEmpty(ll);
	printf("is empty? : %d\n",e);

	d1 = GetFirstLinkedList(ll);
	printf("First %d\n", d1->a);

	d1 = GetLastLinkedList(ll);
	printf("Last %d\n", d1->a);

	printf("//////////////////////\n");

	AddFirstLinkedList(ll, g);
	e = LinkedListIsEmpty(ll);
	printf("is empty? : %d\n",e);

	d1 = GetFirstLinkedList(ll);
	printf("First %d\n", d1->a);

	d1 = GetLastLinkedList(ll);
	printf("Last %d\n", d1->a);

	RemoveFirstLinkedList(ll);
	printf("----------------------\n");
	printf("is empty? : %d\n",e);

	d1 = GetFirstLinkedList(ll);
	printf("First %d\n", d1->a);

	d1 = GetLastLinkedList(ll);
	printf("Last %d\n", d1->a);

	RemoveLastLinkedList(ll);
	printf("++++++++++++++++++++++\n");
	d1 = GetLastLinkedList(ll);
	printf("Last %d\n", d1->a);

	return 0;
}
