#include "my_libc.h"

int
my_isalnum(int c)
{
	return (my_isalpha(c) || my_isdigit(c));
}