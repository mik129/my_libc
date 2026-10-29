#include "my_libc.h"

int
my_isprint(int c)
{
	return (c >= 32 && c <= 126);
}