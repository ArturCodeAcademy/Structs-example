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
	struct node* it = list.head;
	for (int i = 1; i < size; i++)
	{
		it->next = malloc(sizeof(struct node));
		it->next->data = arr[i];
		it->next->next = NULL;
		it = it->next;
	}
	return list;
}

struct node* AddNode(struct LinkedList* list, int data)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		struct node* it = list->head;
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
		struct node* temp = list->head;
		list->head = list->head->next;
		free(temp);
		return;
	}

	struct node* it = list->head;
	while (it->next != NULL)
	{
		if (it->next->data == data)
		{
			struct node* temp = it->next;
			it->next = it->next->next;
			free(temp);
			return;
		}
		it = it->next;
	}
}

void RemoveNode(struct LinkedList* list, struct node* node)
{
	if (list->head == NULL)
	{
		return;
	}

	if (list->head == node)
	{
		struct node* temp = list->head;
		list->head = list->head->next;
		free(temp);
		return;
	}

	struct node* it = list->head;
	while (it->next != NULL)
	{
		if (it->next == node)
		{
			struct node* temp = it->next;
			it->next = it->next->next;
			free(temp);
			return;
		}
		it = it->next;
	}
}

void PrintList(struct LinkedList* list)
{
	for (struct node* it = list->head; it != NULL; it = it->next)
	{
		printf("%d -> ", it->data);
	}
	printf("NULL\n");
}

struct node* FindNode(struct LinkedList* list, int data)
{
	for (struct node* it = list->head; it != NULL; it = it->next)
	{
		if (it->data == data)
		{
			return it;
		}
	}
	return NULL;
}

struct node* FindLastNode(struct LinkedList* list, int data)
{
	struct node* lastNode = NULL;
	for (struct node* it = list->head; it != NULL; it = it->next)
	{
		if (it->data == data)
		{
			lastNode = it;
		}
	}
	return lastNode;
}

struct node* FindNthNode(struct LinkedList* list, int n)
{
	struct node* it = list->head;
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

struct node* FindNodeByCondition(struct LinkedList* list, int(*condition)(int))
{
	for (struct node* it = list->head; it != NULL; it = it->next)
	{
		if (condition(it->data))
		{
			return it;
		}
	}
	return NULL;
}

struct node* FindLastNodeByCondition(struct LinkedList* list, int(*condition)(int))
{
	struct node* lastNode = NULL;
	for (struct node* it = list->head; it != NULL; it = it->next)
	{
		if (condition(it->data))
		{
			lastNode = it;
		}
	}
	return lastNode;
}
