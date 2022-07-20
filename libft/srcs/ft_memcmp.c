#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (i < n && (p1 || p2))
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		i++;
	}
	return (0);
}