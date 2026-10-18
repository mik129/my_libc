#include "my_libc.h"

static void *(*volatile memset_p)(void *, int, size_t) = my_memset;

void
my_explicit_bzero(void *buf, size_t len)
{
	memset_p(buf, 0, len);
}