#include <iostream>

int cmp_int (void* a, void* b)
{
	return (*(int*)a - *(int*)b);
}

//template <typename T>

void VoidMergeSort (void* arr, size_t size, int size_element, int (*cmp)(void*, void*))
{
	if (size == 1) return;

	VoidMergeSort (arr, size / 2, size_element, cmp);
	VoidMergeSort ((char*)arr + (size / 2) * size_element, (size + 1) / 2, size_element, cmp);

	void* dynamic_space = malloc(size * size_element);
	if (dynamic_space == nullptr)
	{
		std::cout << "Memory error";
		return;
	}

	char* ptr = (char*)dynamic_space;
	char* aptr = (char*)arr;

	int i = 0;
	int j = 0;

	while (i < (size / 2 * size_element) && j < (size + 1) / 2 * size_element)
	{
		if (cmp(((char*)arr + i), ((char*)arr + ((size / 2) * size_element) + j)) <= 0)
		{
			for (int byte = 0; byte < size_element; byte++)
			{
				*ptr++ = aptr[i++];
			}
		}
		else
		{
			for (int byte = 0; byte < size_element; byte++)
			{
				*ptr++ = aptr[size / 2 * size_element + j++];
			}
		}
	}

	while (i < size / 2 * size_element)
	{
		for (int byte = 0; byte < size_element; byte++)
		{
			*ptr++ = aptr[i++];
		}
	}

	while (j < (size + 1) / 2 * size_element)
	{
		for (int byte = 0; byte < size_element; byte++)
		{
			*ptr++ = aptr[size / 2 * size_element + j++];
		}
	}

	ptr -= size * size_element;

	for (int byte = 0; byte < (size * size_element); byte++)
	{
		aptr[byte] = ptr[byte];
	}

	free (dynamic_space);
}