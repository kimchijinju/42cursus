/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/25 21:08:51 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include "philosopher.h"

void	init_argment(t_option *opt, int argc, char **argv)
{
	opt->number_of_philosophers = ft_atoi(argv[1]);
	opt->time_to_die = ft_atoi(argv[2]);
	opt->time_to_eat = ft_atoi(argv[3]);
	opt->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		opt->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	print_log(t_philo_identity *_this, char *log)
{
	double	time;

	gettimeofday(&_this->log_time, NULL);
	time = get_millisecond(_this->log_time)
		- get_millisecond(_this->start_time);
	printf("%.0f %d %s\n", time, _this->seq, log);
}

bool	shared_variable_init(t_option *opt, t_philo_identity **p, pthread_t **t)
{
	*p = malloc(sizeof(t_philo_identity)
			* opt->number_of_philosophers);
	*t = malloc(sizeof(pthread_t) * opt->number_of_philosophers);
	(*p)->shared = malloc(sizeof(t_shared_variable));
	(*p)->shared->m_fork = malloc(sizeof(pthread_mutex_t)
			* opt->number_of_philosophers);
	(*p)->shared->m_died = malloc(sizeof(pthread_mutex_t));
	(*p)->shared->last_eat_time = malloc(sizeof(struct timeval)
			* opt->number_of_philosophers);
	if (!*t || !(*p)->shared || !(*p)->shared->m_fork
		|| !(*p)->shared->m_died || !(*p)->shared->last_eat_time)
	{
		free(*t);
		free((*p)->shared);
		free((*p)->shared->m_fork);
		free((*p)->shared->m_died);
		free((*p)->shared->last_eat_time);
		return (false);
	}
	(*p)->shared->opt = opt;
	return (true);
}

void	mutex_init(t_shared_variable *shared)
{
	int	i;

	i = 0;
	while (i < shared->opt->number_of_philosophers)
	{
		pthread_mutex_init(&(shared->m_fork[i]), NULL);
		++i;
	}
	pthread_mutex_init(shared->m_died, NULL);
}

bool	birth_philosopher(t_option *opt, t_philo_identity **philosophers, pthread_t **thread)
{
	int	i;

	if (shared_variable_init(opt, philosophers, thread) == false)
		return (false);
	mutex_init((*philosophers)->shared);
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		(*philosophers)[i].shared = (*philosophers)->shared;
		(*philosophers)[i].seq = i;
		(*philosophers)[i].who_died = false;
		gettimeofday(&(*philosophers)[i].start_time, NULL);
		gettimeofday(&(*philosophers)[i].shared->last_eat_time[i], NULL);
		if (i % 2 == 0)
			usleep(30);
		pthread_create(&(*thread)[i], NULL,
			philosopher_life_cycle, &(*philosophers)[i]);
		++i;
	}
	return (true);
}

void	wait_and_destory(t_philo_identity *philosophers, pthread_t *thread);
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
	wait_and_destory(philosophers, thread);
}
