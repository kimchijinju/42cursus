#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*str;
	unsigned int 	i;

	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * s_len + 1);
	if(!str)
		return (NULL);
	i = 0;
	while(s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
};