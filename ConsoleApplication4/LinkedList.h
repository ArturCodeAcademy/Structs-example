#pragma once
#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode
{
	int data;
	struct LinkedListNode* next;
};

struct LinkedList
{
	struct LinkedListNode* head;
};

struct LinkedList CreateLinkedList();
struct LinkedList CreateLinkedListFromArray(int* arr, int size);
struct LinkedListNode* AddNode(struct LinkedList* list, int data);
void RemoveElement(struct LinkedList* list, int data);
void RemoveNode(struct LinkedList* list, struct LinkedListNode* node);
void PrintList(struct LinkedList* list);
struct LinkedListNode* FindNode(struct LinkedList* list, int data);
struct LinkedListNode* FindLastNode(struct LinkedList* list, int data);
struct LinkedListNode* FindNthNode(struct LinkedList* list, int n);
struct LinkedListNode* FindNodeByCondition(struct LinkedList* list, int(*condition)(int));
struct LinkedListNode* FindLastNodeByCondition(struct LinkedList* list, int(*condition)(int));
