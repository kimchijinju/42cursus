#include <stdlib.h>


static int	len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*put_string(const char *s, char c)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * len(s, c) + 1);
	if (!copy)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	get_malloc_size(const char *s, char c)
{
	int	count;

	count = 1;
	while (*s)
	{
		while (c == *s && *s)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}
static void	free_split(char **s, int i)
{
	while(i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
}
char **ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = malloc(sizeof(char *) * get_malloc_size(s, c));
	if(!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		split[i++] = put_string(s, c);
		if(!split[i - 1])
		{
			free_split(split, i - 1);
			return (NULL);
		}
		while (*s != c && *s)
			s++;
	}
	split[i] = NULL;
	return (split);
}