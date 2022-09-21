/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:35:00 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 11:35:11 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include "checker.h"
#include "command.h"

static t_bool	command_success(char *str, t_deque *a, t_deque *b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	deque_sorted(t_deque *a)
{
	int	i;
	int	back;
	int	back_next;

	if (a->cur_size != a->max_size)
		return (FALSE);
	i = 0;
	while (i < a->cur_size - 1)
	{
		back = (a->back - 1 - i + a->max_size) % a->max_size;
		back_next = (back - 1 + a->max_size) % a->max_size;
		if (a->arr[back] > a->arr[back_next])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	get_command_and_sort(t_deque *a, t_deque *b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		if (command_success(cmd, a, b) == FALSE)
		{
			free(cmd);
			error();
			return (FALSE);
		}
		free(cmd);
	}
	if (deque_sorted(a))
		return (TRUE);
	else
		return (FALSE);
}
