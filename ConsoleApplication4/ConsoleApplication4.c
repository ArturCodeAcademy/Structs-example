#include "LinkedList.h"	

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	struct LinkedList list = CreateLinkedListFromArray(arr, 5);
	

	PrintList(&list);
	// RemoveElement(&list, 5);
	// RemoveNode(&list, n);
	// PrintList(&list);
	struct node* f = FindNode(&list, 5);
	struct node* l = FindLastNode(&list, 5);

	printf("Found node: %d, Next: %d\n", f->data, f->next->data);
	printf("Found last node: %d, Next: %d\n", l->data, l->next->data);

	return 0;
}
