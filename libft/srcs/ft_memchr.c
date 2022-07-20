#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	while(n)
	{
		if(*(unsigned char *)s == (unsigned char) c)
			return ((void *) s);
		s++;
		n--;
	}
	return (NULL);
}