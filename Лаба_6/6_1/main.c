#include <stdio.h>
#include "typs.h"
#include "sources.h"

int main() {
	DblLinkedList* list = createDblLinkedList();
	int keyW = 1;
	int keyB = 2;
	int a = 1;
	int b = 1;
	int c = 2;
	int d = 1;
	int e = 2;
	int f = 2;
	int g = 1;

	pushFront(list, &a);
	pushFront(list, &b);
	pushFront(list, &c);
	pushBack(list, &d);
	pushBack(list, &e);
	pushBack(list, &f);
	pushBack(list, &g);
	printDblLinkedList(list, printInt);

	int i = 0;
	int len = list->size;
	int k = 1;
	Node* temporaryWhite = NULL;
	Node* temporaryBlack = NULL;
	Node* tmp1 = list->head;
	Node* tmp2 = list->tail;
	while (tmp1 != tmp2) {
		if (*(tmp1->value) == 2)
			temporaryWhite = getNthq(list, i);
		if (*(tmp2->value) == 1)
			temporaryBlack = getNthq(list, len - k);
		if ((temporaryBlack != NULL) && (temporaryWhite != NULL)) {
			tmp1 = tmp1->next;
			tmp2 = tmp2->prev;
			deleteNth(list, i);
			deleteNth(list, len - k - 1);
			//printDblLinkedList(list, printInt);
			insert(list, i, &keyW);
			insert(list, len - k - 1, &keyB);
			//printDblLinkedList(list, printInt);
			temporaryWhite = NULL;
			temporaryBlack = NULL;
			i++;
			k++;
		}
		else {
			if ((temporaryBlack == NULL) && (temporaryWhite != NULL)) {
				k++;
				tmp2 = tmp2->prev;
			}
			if ((temporaryWhite == NULL) && (temporaryBlack != NULL)) {
				tmp1 = tmp1->next;
				i++;
			}

			if ((temporaryBlack == NULL) && (temporaryWhite == NULL)) {
				tmp1 = tmp1->next;
				tmp2 = tmp2->prev;
				k++;
				i++;

			}

		}



	}
	printDblLinkedList(list, printInt);
	deleteDblLinkedList(&list);
	return 0;
}