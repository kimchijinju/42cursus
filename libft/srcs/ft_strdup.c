#include "libft.h"

static void	cpy(char *s1, const char *s2)
{
	while(*s2)
		*s1++ = *s2++;
	*s1 = '\0';
}

char	*ft_strdup(const char *s1)
{
	size_t 	len;
	char	*str;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	cpy(str, s1);
	return (str);
}