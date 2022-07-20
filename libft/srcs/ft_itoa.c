#include "libft.h"
#include <stdio.h>

static int	get_size(long long nb)
{
	int size;

	size = 0;
	if(nb <= 0)
	{
		size++;
		nb = -nb;
	}
	while(nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void	put(long long nb, char *str)
{
	char	n;
	int 	i;

	i = get_size(nb);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (nb)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
}

char *ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(char) * get_size(n) + 1);
	if (!str)
		return (NULL);
	put(n, str);
	return (str);
}

int main(int argc, char **argv)
{
	printf("%s", ft_itoa(ft_atoi(argv[1])));
}