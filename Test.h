#pragma once
void IntArrayTestPrint(int* correct_array, int* test_array, size_t arr_size);
int* CreateCopyOfArray(int* src, size_t arr_size);
void SortUnitTest(void (*f_name) (int arr[], size_t size), int passes);
void SortCornerTest(void (*f_name) (int arr[], size_t size));
void SortManualTest(void (*f_name) (int arr[], size_t size));