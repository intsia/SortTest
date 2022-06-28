#include <iostream>
#include <algorithm>
#include "Test.h"
#include "Support.h"
#include <stdlib.h>

bool SortTestResult (int* test_array, int* correct_array, size_t array_size, void (*f_name) (int arr[], size_t size))
{
	std::sort (&correct_array[0], &correct_array[array_size]);		

	f_name (test_array, array_size);							

	bool result = Compare (test_array, correct_array, array_size);			
	if (!result)																
	{																		
		IntArrayTestPrint (test_array, correct_array, array_size);			
	}
	return result;
}


int* ManualInputOfArray (const char prompt[])
{
	printf ("%s\n", prompt);
	printf ("\nPlease enter the size of array and press \"Enter button\": ");

	int array_size = 0;

	scanf_s ("%d", &array_size);

	printf ("\nPlease enter space separated array values and press \"Enter button\": ");

	int* test_array = (int*) calloc (array_size, sizeof(int));
	if (test_array == nullptr) 
	{ 
		printf("Memory error");     //TODO	   description				errno perror sys_errlist 
		return nullptr;
	}	

//	int* test_array = CallocWithReporting (array_size, "test");			   //TODO

	for (int i = 0; i < array_size; ++i)
	{
		scanf_s ("%d", &test_array[i]);
	}

	printf ("\n\n");

	return test_array;
}

/*
void SortManualTest (void (*f_name) (int arr[], size_t size))
{
	printf ("Manual sort test has started!\n");
			
	ManualInputOfArray 

	int* correct_option = CreateCopyOfArray (test_array, array_size);

	SortTestResult (test_array, correct_option, array_size, f_name);

	printf ("Test has finished");

	free
}
*/