#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	char	*str;
	unsigned int	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while(*s1)
		str[i++] = *s1++;
	while(*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}