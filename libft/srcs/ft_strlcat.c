#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	int 	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + dst_len);
	i = 0;
	while (i + 1 + dst_len < dstsize && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);

}