/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:25 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/02 22:03:44 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "deque.h"

static int	error()
{
	write(2, "Error\n", 6);
	return (1);
}

int main(int argc, char **argv)
{
	t_deque	*deque;

	if (argc < 2)
		return (error());
	deque = init(argc, argv);
	if (deque == NULL)
		return (error());
	free(deque->arr);
	free(deque);
	return 0;
}
