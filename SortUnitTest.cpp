#include <iostream>
#include <algorithm>
#include "Support.h"
#include "Comparators.h"
#include "Test.h"
#include "ANSI_COLOR_DEFINE.h"

void IntArrayTestPrint (int* correct_array, int* test_array, size_t arr_size)
{
	printf("%s%s%s", ANSI_COLOR_RED, "Test failed:", ANSI_COLOR_RESET);

	printf("\n%s", "                         ");
	for (size_t i = 0; i < arr_size; ++i)
	{
		printf("[ %llu ] ", i);
	}

	printf("\nValues of test array:    ");
	for (size_t i = 0; i < arr_size; ++i)
	{
		bool ok = (correct_array[i] == test_array[i]);

		printf("%s%5d%s ", (ok ? ANSI_COLOR_GREEN : ANSI_COLOR_RED), test_array[i], ANSI_COLOR_RESET);
	}

	printf("\nValues of correct array: ");
	for (size_t i = 0; i < arr_size; ++i)
	{
		bool ok = (correct_array[i] == test_array[i]);

		printf("%s%5d%s ", (ok ? ANSI_COLOR_GREEN : ANSI_COLOR_RED), correct_array[i], ANSI_COLOR_RESET);
	}

	printf("\n\n\n");
}

int* CreateArrayWithRandomValues (size_t arr_size, size_t min_element_value, size_t max_element_value)
{
	int* arr = (int*)malloc(arr_size * sizeof(int));

	if (arr == nullptr)
	{
		printf("Memory error");
		return nullptr;
	}

	for (int i = 0; i < arr_size; ++i)
	{
		arr[i] = rand() % max_element_value + min_element_value;
	}
	return arr;
}

int* CreateCopyOfArray (int* src, size_t arr_size)
{
	int* arr = (int*)malloc(arr_size * sizeof(int));

	if (arr == nullptr)
	{
		printf("Memory error");
		return nullptr;
	} 

	Copy(arr, src, arr_size * sizeof(int));
	return arr;
}

void SortUnitTest (void (*f_name) (int arr[], size_t size), int passes)
{
	printf("\n%s%s%s\n\n", ANSI_COLOR_MAGENTA, "Sort unit test has started", ANSI_COLOR_RESET);

	for (int i = 0; i < passes; ++i)
	{
		int arr_size = (rand() % 15 + 1);

		int* test_arr = CreateArrayWithRandomValues (arr_size, -50, 100);
		int* correct_option = CreateCopyOfArray (test_arr, arr_size);

		std::sort(&correct_option[0], &correct_option[arr_size]);
		f_name (test_arr, arr_size);

		bool test_result = Compare (test_arr, correct_option, arr_size);

		if (test_result)
		{
			IntArrayTestPrint(correct_option, test_arr, arr_size);
		}

		free (correct_option);
		free (test_arr);
	}

	printf("\n%s%s%s\n\n", ANSI_COLOR_MAGENTA, "Sort unit test has finished", ANSI_COLOR_RESET);
}
