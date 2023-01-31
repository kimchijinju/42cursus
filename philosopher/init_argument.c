/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:45:53 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 14:46:22 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"

void	init_argment(t_option *opt, int argc, char **argv)
{
	opt->number_of_philosophers = ft_atoi(argv[1]);
	opt->time_to_die = ft_atoi(argv[2]);
	opt->time_to_eat = ft_atoi(argv[3]);
	opt->time_to_sleep = ft_atoi(argv[4]);
	opt->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		opt->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	only_digit(char *s)
{
	while (*s)
	{
		if (is_digit(*s) == false)
			return (false);
		++s;
	}
	return (true);
}

bool	valid_argment(int argc, char **argv)
{
	bool	ret;

	ret = (only_digit(argv[1]) && only_digit(argv[2])
			&& only_digit(argv[3]) && only_digit(argv[4]));
	if (argc == 6)
		ret = (ret && only_digit(argv[5]));
	if (ret == false)
		printf("Please enter a positive number only\n");
	return (ret);
}
