#include <algorithm>
#include "Support.h"
#include "Test.h"

void SortCornerTest(void (*f_name) (int arr[], size_t size))
{
	//-------------------------------------------------------------------------------

	#define TEST_ARRAY_( a, b, ARRAY_SIZE )										\
																				\
		int* test_array = a;													\
		int* correct_array = b;													\
		std::sort (&b[0], &b[ARRAY_SIZE]);										\
		f_name (test_array, ARRAY_SIZE);										\
		bool result = Compare (test_array, correct_array, ARRAY_SIZE);			\
		if (result)																\
		{																		\
			IntArrayTestPrint (test_array, correct_array, ARRAY_SIZE);			\
		}

	//-------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------
	{
		int test[1] = { 1 };
		int correct[1] = { 1 };
		TEST_ARRAY_(test, correct, 1)
	}
	//-------------------------------------------------------------------------------
	{
		int test[2] = { 0, -1 };
		int correct[2] = { -1, 0 };
		TEST_ARRAY_(test, correct, 2)
	}
	//------------------------------------------------------------------------------- 
	{
		int test[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int correct[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		TEST_ARRAY_(test, correct, 10)
	}
	//-------------------------------------------------------------------------------
	{
		int test[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
		int correct[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
		TEST_ARRAY_(test, correct, 10)
	}
	//-------------------------------------------------------------------------------
	{
		int test[3] = { -1, 5, 300 };
		int correct[3] = { 300, 5, -1 };
		TEST_ARRAY_(test, correct, 3)
	}
	//-------------------------------------------------------------------------------

#undef TEST_ARRAY_

}