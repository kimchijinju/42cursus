#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	s1_len;

	set_len = ft_strlen(set);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while(ft_strchr(set,s1[s1_len]))
	{
		s1_len--;
		if (s1_len == 0)
			break;
	}
	return ft_substr(s1, 0, s1_len);
}