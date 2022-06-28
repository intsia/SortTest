
void Copy (void* dst, void* src, size_t size_in_bytes)
{
//-----------------------------------------
#define CYCLE_OF_COPY_(TYPE)              \
	while (size_in_bytes >= sizeof(TYPE)) \
	{                                     \
		*(TYPE*)dst = *(TYPE*)src;        \
		size_in_bytes -= sizeof(TYPE);    \
		dst = (TYPE*)dst + 1;			  \
		src = (TYPE*)src + 1;			  \
	} 
//-----------------------------------------
	CYCLE_OF_COPY_(size_t);
	CYCLE_OF_COPY_(int);
	CYCLE_OF_COPY_(short);
	CYCLE_OF_COPY_(char);
//-----------------------------------------
#undef CYCLE_OF_COPY_
}