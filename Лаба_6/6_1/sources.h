
#ifndef HITROVIEBANAYAZADACHA_SOURCES_H
#define HITROVIEBANAYAZADACHA_SOURCES_H

#include "typs.h"
DblLinkedList* createDblLinkedList();
void deleteDblLinkedList(DblLinkedList** list);
void pushBack(DblLinkedList* list, int* value);
Node* getNth(DblLinkedList* list, size_t index);
void insert(DblLinkedList* list, size_t index, int* value);
Node* getNthq(DblLinkedList* list, size_t index);
void pushFront(DblLinkedList* list, int* data);
void printDblLinkedList(DblLinkedList* list, void (*fun)(int*));
void printInt(int* value);
Node* getNth(DblLinkedList* list, size_t index);

#endif 
