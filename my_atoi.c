#include "my_libc.h"

int
my_atoi(const char *nptr)
{
	int sign;
	int res;

	res = 0;
	sign = 1;
	while (my_isspace((unsigned char)*nptr))
		nptr++;
	if (*nptr == '-') {
		sign = -1;
		nptr++;
	} else if (*nptr == '+') {
		nptr++;
	}
	while (my_isdigit((unsigned char)*nptr)) {
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
