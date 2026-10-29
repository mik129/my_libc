#include "my_libc.h"

int
my_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}