#include "DinamicArrayInt.h"

void DoubleCapacityDArrayInt(struct DinamicArrayInt* arr)
{
	if (arr->capacity == 0)
		arr->capacity = 1;
	else
		arr->capacity *= 2;
	int* newData = malloc(arr->capacity * sizeof(int));
	for (int i = 0; i < arr->size; i++)
		newData[i] = arr->data[i];
	free(arr->data);
	arr->data = newData;
}

void InitDArrayInt(struct DinamicArrayInt* arr, int capacity)
{
	if (arr->capacity > 0)
		FreeDArrayInt(arr);

	arr->data = malloc(capacity * sizeof(int));
	arr->size = 0;
	arr->capacity = capacity;
}

void FreeDArrayInt(struct DinamicArrayInt* arr)
{
	free(arr->data);
	arr->data = NULL;
	arr->size = 0;
	arr->capacity = 0;
}

void ResizeDArrayInt(struct DinamicArrayInt* arr)
{
	int* newData = malloc(arr->size * sizeof(int));
	for (int i = 0; i < arr->size; i++)
		newData[i] = arr->data[i];
	free(arr->data);
	arr->data = newData;
	arr->capacity = arr->size;
}

void PushBackDArrayInt(struct DinamicArrayInt* arr, int value)
{
	if (arr->size == arr->capacity)
		DoubleCapacityDArrayInt(arr);
	arr->data[arr->size] = value;
	arr->size++;
}

void PopBackDArrayInt(struct DinamicArrayInt* arr)
{
	if (arr->size == 0)
		return;

	arr->size--;
}

void InsertDArrayInt(struct DinamicArrayInt* arr, int value, int index)
{
	if (index < 0 || index > arr->size)
		return;

	if (arr->size == arr->capacity)
		DoubleCapacityDArrayInt(arr);

	for (int i = arr->size; i > index; i--)
		arr->data[i] = arr->data[i - 1];
	arr->data[index] = value;
	arr->size++;
}

void EraseDArrayInt(struct DinamicArrayInt* arr, int index)
{
	if (index < 0 || index >= arr->size)
		return;

	arr->size--;
	for (int i = index; i < arr->size; i++)
		arr->data[i] = arr->data[i + 1];
}

void PrintDArrayInt(struct DinamicArrayInt* arr)
{
	for (int i = 0; i < arr->size; i++)
		printf("%d ", arr->data[i]);
	printf("\n");
}

void ModifyDArrayInt(struct DinamicArrayInt* arr, int (*modifier)(int))
{
	for (int i = 0; i < arr->size; i++)
		arr->data[i] = modifier(arr->data[i]);
}

void SelectWhereDArrayInt(struct DinamicArrayInt* arrFrom, struct DinamicArrayInt* arrTo, int (*predicate)(int))
{
	InitDArrayInt(arrTo, arrFrom->size);
	for (int i = 0; i < arrFrom->size; i++)
		if (predicate(arrFrom->data[i]))
			PushBackDArrayInt(arrTo, arrFrom->data[i]);
}