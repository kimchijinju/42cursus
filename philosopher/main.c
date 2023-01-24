/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 21:01:26 by hanbkim          ###   ########.fr       */
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

t_shared_variable	*init_shared_variable(t_option *opt, pthread_t **thread)
{
	t_shared_variable	*shared;
	pthread_mutex_t		*m_fork;
	pthread_mutex_t		*m_died;
	struct timeval		*last_eat_time;
	int					i;

	shared = malloc(sizeof(t_shared_variable));
	*thread = malloc(sizeof(pthread_t) * opt->number_of_philosophers);
	m_fork = malloc(sizeof(pthread_mutex_t) * opt->number_of_philosophers);
	m_died = malloc(sizeof(pthread_mutex_t));
	last_eat_time = malloc(sizeof(struct timeval) * opt->number_of_philosophers);
	if (!shared || !*thread || !m_fork || !m_died || !last_eat_time)
	{
		free(shared);
		free(thread);
		free(m_fork);
		free(m_died);
		free(last_eat_time);
		return (false);
	}
	pthread_mutex_init(m_died, NULL);
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		pthread_mutex_init(&(m_fork[i]), NULL);
		++i;
	}
	return (shared);
}

void	birth_philosopher(t_option *opt)
{
	pthread_t			*thread;
	t_shared_variable	*shared;
	t_philo_identity	*philosophers;
	int					i;

	philosophers = malloc(sizeof(t_philo_identity)
			* opt->number_of_philosophers);
	init_shared_variable(opt, &thread);
	
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		philosophers[i].shared = shared;
		philosophers[i].seq = i;
		philosophers[i].who_died = false;
		gettimeofday(&philosophers[i].start_time, NULL);
		gettimeofday(&philosophers[i].last_eat_time[i], NULL);
		pthread_create(&thread[i], NULL,
			philosopher_life_cycle, &philosophers[i]);
		++i;
	}
}

int main(int argc, char **argv)
{
	t_option			opt;
	t_philo_identity	*philosophers;

	if (argc != 5 && argc != 6)
		return (1);
	init_argment(&opt, argc, argv);
	birth_philosopher(&opt);
	monitering_philosophers(philosophers);
}

