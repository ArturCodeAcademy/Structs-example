#include "LinkedList.h"	
#include "DinamicArrayInt.h"
#include "BinaryTree.h"

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
	int arr[] = { 1, 2, 3, 4, 5, 1, 20 };
	struct LinkedList list = CreateLinkedListFromArray(arr, 7);


	PrintList(&list);
	RemoveElement(&list, 5);
	PrintList(&list);
	struct LinkedListNode* f = FindNode(&list, 1);
	struct LinkedListNode* l = FindLastNode(&list, 1);

	printf("Found node: %d, Next: %d\n", f->data, f->next->data);
	printf("Found last node: %d, Next: %d\n", l->data, l->next->data);

	RemoveNode(&list, f);
    PrintList(&list);
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

void TestTree()
{
    struct BinaryTree* tree = CreateBinaryTree();
    int arr[] = { 5, 2, 1, 3, 7, 6, 10, 8, 9, 12 };
    for (int i = 0; i < 10; i++)
        InsertBinaryTree(tree, arr[i]);

    int min = BinaryTreeMin(tree)->data;
    int max = BinaryTreeMax(tree)->data;

    printf("Min: %d\nMax: %d\n", min, max);

    PrintBinarySortedTree(tree);

    int found = BinaryTreeSearch(tree->root, 7) != NULL;
    printf("Found 7: %d\n", found);
    found = BinaryTreeSearch(tree->root, 12) != NULL;
    printf("Found 11: %d\n", found);
}

void Test()
{
    printf("List test\n");
    ListTest();

    printf("\nDinamic array test\n");
    TestDArray();

    printf("\nBinary tree test\n");
    TestTree();
}

int main()
{
   Test();

	return 0;
}
