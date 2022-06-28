
void Swap (void* a, void* b, size_t size_in_bytes)
{
//-------------------------------------------
#define CYCLE_OF_SWAP_(TYPE)				\
	while (size_in_bytes >= sizeof(TYPE))	\
		{									\
			TYPE buffer = *(TYPE*)a;		\
			*(TYPE*)a = *(TYPE*)b;			\
			*(TYPE*)b = buffer;				\
			size_in_bytes -= sizeof(TYPE);	\
			a = (TYPE*)a + 1;				\
			b = (TYPE*)b + 1;				\
		}
//-------------------------------------------
	CYCLE_OF_SWAP_(size_t);
	CYCLE_OF_SWAP_(int);
	CYCLE_OF_SWAP_(short);
	CYCLE_OF_SWAP_(char);
//-------------------------------------------
#undef CYCLE_OF_SWAP_
}