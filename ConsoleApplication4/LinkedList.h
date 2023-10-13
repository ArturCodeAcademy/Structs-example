#pragma once
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct LinkedList
{
	struct node* head;
};

struct LinkedList CreateLinkedList();
struct LinkedList CreateLinkedListFromArray(int* arr, int size);
struct node* AddNode(struct LinkedList* list, int data);
void RemoveElement(struct LinkedList* list, int data);
void RemoveNode(struct LinkedList* list, struct node* node);
void PrintList(struct LinkedList* list);
struct node* FindNode(struct LinkedList* list, int data);
struct node* FindLastNode(struct LinkedList* list, int data);
