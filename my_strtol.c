#include "my_libc.h"
#include <errno.h>
#include <limits.h>

long
my_strtol(const char *nptr, char **endptr, int base)
{
	const char *s;
	unsigned long acc;
	char c;
	unsigned long cutoff;
	int neg, any, cutlim;

	s = nptr;
	while (my_isspace((unsigned char)*s))
		s++;
	neg = 0;
	if (*s == '-') {
		neg = 1;
		s++;
	} else if (*s == '+') {
		s++;
	}
	if ((base == 0 || base == 16) && *s == '0' &&
	    (*(s + 1) == 'x' || *(s + 1) == 'X')) {
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = (*s == '0') ? 8 : 10;
	if (base < 2 || base > 36) {
		errno = EINVAL;
		if (endptr != NULL)
			*endptr = (char *)nptr;
		return (0);
	}
	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	for (acc = 0, any = 0;; c = *s++) {
		if (my_isdigit((unsigned char)c))
			c -= '0';
		else if (my_isalpha((unsigned char)c))
			c -= my_isupper((unsigned char)c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0)
			continue;
		if (acc > cutoff || (acc == cutoff && c > cutlim)) {
			any = -1;
			acc = cutoff;
			errno = ERANGE;
		} else {
			any = 1;
			acc = acc * (unsigned long)base + c;
		}
	}
	if (any < 0) {
		acc = neg ? (unsigned long)LONG_MIN : (unsigned long)LONG_MAX;
	} else if (neg) {
		acc = (unsigned long)-(long)acc;
	}
	if (endptr != NULL)
		*endptr = (char *)(any ? s - 1 : nptr);
	return ((long)acc);
}