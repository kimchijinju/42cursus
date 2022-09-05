#include "libft/libft.h"
#include "push_swap.h"
#include "bool.h"
#include "deque.h"

size_t	get_element_count(char **input)
{
	size_t	i;

	i = 0;
	while(input[i] != NULL)
		i++;
	return (i);
}

static t_bool	is_incorrect_string(char *str)
{
	size_t	i;
	t_bool	sign;

	i = 0;
	sign = str[i] == '-' || str[i] == '+';
	if (sign)
		str++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (TRUE);
		i++;
	}
	return (i == 0);
}
static t_bool	integer_range_out(char *str)
{
	long long	number;
	int			sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (TRUE);
	return (FALSE);
}

static t_bool	wrong_input(char *str)
{
	if (is_incorrect_string(str))
	{
		return (TRUE);
	}
	if (integer_range_out(str))
	{
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	duplicate_input(int *arr, size_t arr_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (arr[i] == arr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

char	**parse_input(int argc, char **argv)
{
	int		i;
	char	*join;
	char	*temp;
	char	**split;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin_with_space(join, argv[i]);
		if (temp == NULL)
		{
			free(join);
			return (NULL);
		}
		free(join);
		join = temp;
		i++;
	}
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

static t_bool	init_element(t_deque *deque, size_t arr_size, char **input)
{
	size_t	i;

	i = 0;
	while(i < arr_size)
	{
		if (wrong_input(input[i]))
			return (FALSE);
		deque->push_back(deque, ft_atoi(input[i]));
		i++;
	}
	return (TRUE);
}

void	*free_deque(t_deque *deque)
{
	free(deque->arr);
	free(deque);
	return (NULL);
}

t_deque	*create_deque_and_fill_array(char **input, size_t element_size)
{
	t_deque	*deque;

	deque = create_deque(element_size);
	if (deque == NULL)
		return (NULL);
	if (!init_element(deque, element_size, input))
		return (free_deque(deque));
	if (duplicate_input(deque->arr, element_size))
		return (free_deque(deque));
	return (deque);
}

t_bool	init_deque(t_deque **a, t_deque **b, char **input, size_t element_size)
{
	*a = create_deque_and_fill_array(input, element_size);
	free_split(input, element_size);
	if (*a == NULL)
		return (FALSE);
	*b = create_deque(element_size);
	if (*b == NULL)
	{
		free_deque(*a);
		return (FALSE);
	}
	return (TRUE);
}
