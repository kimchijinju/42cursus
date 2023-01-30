/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/30 18:00:18 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	init_argment(t_option *opt, int argc, char **argv)
{
	opt->number_of_philosophers = ft_atoi(argv[1]);
	opt->time_to_die = ft_atoi(argv[2]);
	opt->time_to_eat = ft_atoi(argv[3]);
	opt->time_to_sleep = ft_atoi(argv[4]);
	opt->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		opt->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_option			opt;
	t_philo_identity	*philosophers;
	pthread_t			*thread;

	if (argc != 5 && argc != 6)
		return (1);
	init_argment(&opt, argc, argv);
	if (birth_philosopher(&opt, &philosophers, &thread) == false)
		return (1);
	monitering_philosophers(philosophers);
	wait_thread(philosophers->shared, thread);
	return (0);
}
