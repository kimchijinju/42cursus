#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t 	i;

	if(src > dst)
	{
		i = 0;
		while(i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	return (dst);
}
