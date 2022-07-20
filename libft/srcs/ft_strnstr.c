#include "libft.h"

char 	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (*haystack && len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}