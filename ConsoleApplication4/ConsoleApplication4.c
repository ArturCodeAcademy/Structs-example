#include "LinkedList.h"	
#include "DinamicArrayInt.h"	

int Double(int value)
{
	return value * 2;
}

int Triple(int value)
{
	return value * 3;
}

int NullIfOdd(int value)
{
	if (value % 2 == 1)
		return 0;
	return value;
}

void ListTest()
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
}

void TestDArray()
{
    struct DinamicArrayInt arr, otherArr;
    InitDArrayInt(&arr, 0);
    for (int i = 0; i < 10; i++)
    {
        if (i == 7)
        {
            PopBackDArrayInt(&arr);
            printf("%3d) %5d %5d: ", i, arr.size, arr.capacity);
            PrintDArrayInt(&arr);
        }
        PushBackDArrayInt(&arr, i);
        printf("%3d) %5d %5d: ", i, arr.size, arr.capacity);
        PrintDArrayInt(&arr);
    }

    InsertDArrayInt(&arr, 100, 2);
    PrintDArrayInt(&arr);

    EraseDArrayInt(&arr, 5);
    PrintDArrayInt(&arr);

    ModifyDArrayInt(&arr, &Triple);
    PrintDArrayInt(&arr);

    ModifyDArrayInt(&arr, &NullIfOdd);
    PrintDArrayInt(&arr);

    SelectWhereDArrayInt(&arr, &otherArr, &NullIfOdd);
    PrintDArrayInt(&otherArr);

    FreeDArrayInt(&arr);
    FreeDArrayInt(&otherArr);
    return 0;
}

int main()
{
	//ListTest();
	TestDArray();

	return 0;
}
