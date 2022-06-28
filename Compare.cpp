
//возвращает TRUE если "куски" памяти идентичны

bool VoidCompare (void* first, void* second, size_t size_in_bytes) 
{
//-----------------------------------------------
#define CYCLE_OF_COMPARING_(TYPE)				\
	while (size_in_bytes >= sizeof(TYPE))		\
	{											\
		if (*(TYPE*)first != *(TYPE*)second)	\
		{										\
			return false;						\
		}										\
		size_in_bytes -= sizeof(TYPE);			\
		first = (TYPE*)first + 1;				\
		second = (TYPE*)second + 1;				\
	}


//-----------------------------------------------
	CYCLE_OF_COMPARING_(size_t);
	CYCLE_OF_COMPARING_(int);
	CYCLE_OF_COMPARING_(short);
	CYCLE_OF_COMPARING_(char);
//-----------------------------------------------
	return true;

#undef CYCLE_OF_COMPARING_
}

/*
template <typename T>
const T* Compare (const T* first, const T* second, size_t size_in_elements)
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
*/
