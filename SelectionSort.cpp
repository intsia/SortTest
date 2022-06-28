#include <iostream>
#include "Support.h"


int IntMaxIndex (int arr[], size_t arr_size)
{
	int index_max = 0;

	for (size_t i = 1; i < arr_size; ++i)
	{
		if (arr [i] > arr [index_max])
		{
			index_max = i;
		}
	}
	return index_max;
}


int IntMinIndex (int arr[], size_t arr_size)
{
	int index_min = 0;

	for (size_t i = 1; i < arr_size; ++i)
	{
		if (arr[i] < arr [index_min])
		{
			index_min = i;
		}
	}
	return index_min;
}


void SelectionSort (int arr[], size_t size)
{
	for (size_t pass = 0; pass < size / 2; ++pass)
	{
		int min = IntMinIndex (&arr[pass], size - pass*2);
		Swap (&arr[pass], &arr[min + pass], sizeof (arr[0]));

		int max = IntMaxIndex (&arr[pass], size - pass*2);
		Swap (&arr[size - pass - 1], &arr[max + pass], sizeof (arr[0]));
	}
}
