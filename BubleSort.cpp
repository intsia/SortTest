
#include "Support.h"

template <typename T>

void BubleSort (T arr[], size_t size)
{
	for (T pass = 0; pass < size; ++pass)
	{
		for (T i = 0; i < size - 1 - pass; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap (&arr[i], &arr[i + 1], sizeof(arr[0]));
			}
		}
	}
}