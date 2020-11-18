#include <iostream>
#include "Sort.h"

int SearchBinary(int* arr, int array_size, int key)
{
	int mid = 0;
	int left = 0;
	int right = array_size - 1;
	while (1)
	{
		mid = (left + right) / 2;

		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;

		if (left > right)
			return -1;
	}
}

void QuickSort(int* mas, int array_size) 
{
	int i = 0;
	int j = array_size - 1;
	int mid = mas[array_size / 2];
	int tmp;
	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}
		if (i <= j) {
			tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		QuickSort(mas, j + 1);
	}
	if (i < array_size) {
		QuickSort(&mas[i], array_size - i);
	}
}

void InsertionSort(int* arr, int array_size)
{
	int temp;
	for (int i = 1; i < array_size; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
}

void BogoSort(int* arr, int array_size)
{
	int i = 0, temp;
	while (i < array_size - 1)
	{
		if (arr[i + 1] < arr[i])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else i++;
	}
}

void CountingSort(char* arr, int size) 
{
	char* output = new char[size];
	int count[256], i;
	for (i = 0; i < 256; i++)
		count[i] = 0;
	for (int i = 0; i < size; i++)
		count[arr[i]]++;
	for (i = 1; i <= 255; i++)
		count[i] += count[i - 1];
	for (i = 0; i < size; i++)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]] --;
	}
	for (i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
}

bool isSorted(int* arr, int array_size)
{
	bool flag = true;
	for (int i = 0; i < array_size - 1; i++)
		if (arr[i] > arr[i + 1])
			flag = false;
	return flag;
}