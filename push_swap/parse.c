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

static t_bool	wrong_input(char *str)
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

static char	**parse_input(size_t argc, char **argv)
{
	size_t	i;
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

static int	*init_element(t_deque *deque, size_t arr_size, char **input)
{
	size_t	i;

	i = 0;
	while(i < arr_size)
	{
		if (wrong_input(input[i]))
			return (NULL);
		deque->push_back(deque, ft_atoi(input[i]));
		i++;
	}
	return (arr);
}

t_deque	*init_deque(int argc, char **argv)
{
	t_deque	*deque;
	char	**input;
	size_t	element_size;

	input = parse_input(argc, argv);
	if (input == NULL)
		return (NULL);
	element_size = get_element_count(input);
	deque->create_deque(element_size);
	if (!deque)
		return (free_split(input, element_size));
	//todo : 가드 구현
	deque->arr = init_element(deque, element_size, input);
	free_split(input, element_size);
	if (arr == NULL)
		return (NULL);
 	if (duplicate_input(arr, element_size))
	{
		free(arr);
		return (NULL);
	}
	for (int i = 0; i < (int) element_size; i++) {
		printf("%d\n", arr[i]);
	}
	return (arr);
}
