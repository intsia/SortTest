
int IntCompare (void* a, void* b)
{
	return (*(int*)a -  *(int*)b);
}

int ConstIntCompare (const void* a, const void* b)
{
	return (*(const int*)a - *(const int*)b);
}