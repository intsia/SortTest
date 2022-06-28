#pragma once
void Swap (void* a, void* b, size_t type_size);
void Copy (void* to, void* from, size_t size_in_bytes);

template <typename T> const T* Compare(const T* first, const T* second, size_t size_in_elements)
{

	for (size_t i = 0; i < size_in_elements; ++i)
	{
		if (first[i] != second[i])
		{
			return &first[i];
		}
	}

	return nullptr;
}