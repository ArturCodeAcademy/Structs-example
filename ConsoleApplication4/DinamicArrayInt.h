#pragma once

#include <stdlib.h>

struct DinamicArrayInt
{
	int* data;
	int size;
	int capacity;
};

void InitDArrayInt(struct DinamicArrayInt* arr, int capacity);
void FreeDArrayInt(struct DinamicArrayInt* arr);
void ResizeDArrayInt(struct DinamicArrayInt* arr);
void PushBackDArrayInt(struct DinamicArrayInt* arr, int value);
void PopBackDArrayInt(struct DinamicArrayInt* arr);
void InsertDArrayInt(struct DinamicArrayInt* arr, int value, int index);
void EraseDArrayInt(struct DinamicArrayInt* arr, int index);
void PrintDArrayInt(struct DinamicArrayInt* arr);
void ModifyDArrayInt(struct DinamicArrayInt* arr, int (*modifier)(int));
void SelectWhereDArrayInt(struct DinamicArrayInt* arrFrom, struct DinamicArrayInt* arrTo, int (*predicate)(int));
