#include "LinkedList.h"

struct LinkedList CreateLinkedList()
{
	struct LinkedList list;
	list.head = NULL;
	return list;
}

struct LinkedList CreateLinkedListFromArray(int* arr, int size)
{
	struct LinkedList list = CreateLinkedList();
	AddNode(&list, arr[0]);
	struct LinkedListNode* it = list.head;
	for (int i = 1; i < size; i++)
	{
		it->next = malloc(sizeof(struct LinkedListNode));
		it->next->data = arr[i];
		it->next->next = NULL;
		it = it->next;
	}
	return list;
}

struct LinkedListNode* AddNode(struct LinkedList* list, int data)
{
	struct LinkedListNode* newNode = malloc(sizeof(struct LinkedListNode));
	newNode->data = data;
	newNode->next = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		struct LinkedListNode* it = list->head;
		while (it->next != NULL)
		{
			it = it->next;
		}
		it->next = newNode;
	}

	return newNode;
}

void RemoveElement(struct LinkedList* list, int data)
{
	if (list->head == NULL)
	{
		return;
	}

	if (list->head->data == data)
	{
		struct LinkedListNode* temp = list->head;
		list->head = list->head->next;
		free(temp);
		return;
	}

	struct LinkedListNode* it = list->head;
	while (it->next != NULL)
	{
		if (it->next->data == data)
		{
			struct LinkedListNode* temp = it->next;
			it->next = it->next->next;
			free(temp);
			return;
		}
		it = it->next;
	}
}

void RemoveNode(struct LinkedList* list, struct LinkedListNode* node)
{
	if (list->head == NULL)
	{
		return;
	}

	if (list->head == node)
	{
		struct LinkedListNode* temp = list->head;
		list->head = list->head->next;
		free(temp);
		return;
	}

	struct LinkedListNode* it = list->head;
	while (it->next != NULL)
	{
		if (it->next == node)
		{
			struct LinkedListNode* temp = it->next;
			it->next = it->next->next;
			free(temp);
			return;
		}
		it = it->next;
	}
}

void PrintList(struct LinkedList* list)
{
	for (struct LinkedListNode* it = list->head; it != NULL; it = it->next)
	{
		printf("%d -> ", it->data);
	}
	printf("NULL\n");
}

struct LinkedListNode* FindNode(struct LinkedList* list, int data)
{
	for (struct LinkedListNode* it = list->head; it != NULL; it = it->next)
	{
		if (it->data == data)
		{
			return it;
		}
	}
	return NULL;
}

struct LinkedListNode* FindLastNode(struct LinkedList* list, int data)
{
	struct LinkedListNode* lastNode = NULL;
	for (struct LinkedListNode* it = list->head; it != NULL; it = it->next)
	{
		if (it->data == data)
		{
			lastNode = it;
		}
	}
	return lastNode;
}

struct LinkedListNode* FindNthNode(struct LinkedList* list, int n)
{
	struct LinkedListNode* it = list->head;
	for (int i = 0; i < n; i++)
	{
		if (it == NULL)
		{
			return NULL;
		}
		it = it->next;
	}
	return it;
}

struct LinkedListNode* FindNodeByCondition(struct LinkedList* list, int(*condition)(int))
{
	for (struct LinkedListNode* it = list->head; it != NULL; it = it->next)
	{
		if (condition(it->data))
		{
			return it;
		}
	}
	return NULL;
}

struct LinkedListNode* FindLastNodeByCondition(struct LinkedList* list, int(*condition)(int))
{
	struct LinkedListNode* lastNode = NULL;
	for (struct LinkedListNode* it = list->head; it != NULL; it = it->next)
	{
		if (condition(it->data))
		{
			lastNode = it;
		}
	}
	return lastNode;
}
