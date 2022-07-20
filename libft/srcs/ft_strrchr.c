#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	if (c == '\0')
		return ((char *) s);
	while (*s)
	{
		if (*s == c)
			p = (char *) s;
		s++;
	}
	return (p);
}