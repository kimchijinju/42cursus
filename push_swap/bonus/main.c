/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:25 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 11:35:50 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return (1);
}

static void	ok(void)
{
	write(2, "OK\n", 3);
}

static void	ko(void)
{
	write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	char	**input;

	if (argc < 2)
		return (0);
	input = parse_input(argc, argv);
	if (input == NULL)
		return (error());
	if (init_deque(&a, &b, input) == FALSE)
		return (error());
	if (get_command_and_sort(a, b) == TRUE)
		ok();
	else
		ko();
	free_deque(a);
	free_deque(b);
	return (0);
}
