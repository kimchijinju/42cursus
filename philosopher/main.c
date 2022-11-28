/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/28 17:30:16 by hanbkim          ###   ########.fr       */
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

void	think_future(t_philo_identity *self)
{
	const int	seq = self->seq;
	const int	left = (seq + 1) % self->opt->number_of_philosophers;
	const int	right = (seq - 1 + self->opt->number_of_philosophers) % self->opt->number_of_philosophers;
	
	while (1)
	{
		if (self->state[left] != EATING)
			break ;
	}
}

void	eat_spaghetti(t_philo_identity *self)
{
	const int	seq = self->seq;
	const int	left = (seq + 1) % self->opt->number_of_philosophers;
	const int	right = (seq - 1 + self->opt->number_of_philosophers) % self->opt->number_of_philosophers;

	self->state[seq] = HUNGRY;
	if (self->state[right]);
}

void	take_up_fork(t_philo_identity *self)
{
	
}

void	take_down_fork(t_philo_identity *self)
{
	const int	seq = self->seq;
	const int	left = (seq + 1) % self->opt->number_of_philosophers;
	const int	right = (seq - 1 + self->opt->number_of_philosophers) % self->opt->number_of_philosophers;
	
	while(1)
	{
		if (self->state[left] == HUNGRY || self->state[right] == HUNGRY)
		{
			pthread_mutex_unlock(&self->fork[seq]);
			pthread_mutex_unlock(&self->fork[right]);
			break ;
		}
	}
	self->state[seq] = THINKING;
}

void	*philosopher_life_cycle(void *arg)
{
	t_philo_identity	*self;

	self = (t_philo_identity *)arg;

	while (1)
	{
		think_future(self);
		take_up_fork(self);
		eat_spaghetti(self);
		take_down_fork(self);
		sleep(1);
	}
	return (0);
}

void	birth_philosopher(t_option *opt)
{
	t_philo_identity	*philosophers;
	pthread_t			*thread;
	pthread_mutex_t		*mutex_fork;
	enum e_philo_state	*state;
	int				i;

	// malloc guard
	thread = malloc(sizeof(pthread_t) * opt->number_of_philosophers);
	philosophers = malloc(sizeof(t_philo_identity) * opt->number_of_philosophers);
	mutex_fork = malloc(sizeof(pthread_mutex_t) * opt->number_of_philosophers);
	state = malloc(sizeof(enum e_philo_state) * opt->number_of_philosophers);
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		pthread_mutex_init(&(mutex_fork[i]), NULL);
		state[i] = THINKING;
		i++;
	}
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		philosophers[i].fork = mutex_fork;
		philosophers[i].state = state;
		philosophers[i].seq = i;
		philosophers[i].opt = opt;
		pthread_create(&thread[i], NULL, philosopher_life_cycle, &philosophers[i]);
		//sleep(1);
		//table->seq++;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_option	opt;

	if (argc != 5 && argc != 6)
		return (1);
	init_argment(&opt, argc, argv);
	birth_philosopher(&opt);
	while(1);
}

void	time_test(void)
{
	struct timeval	start_time, end_time;

	gettimeofday(&start_time, NULL);
	while (1)
	{
		gettimeofday(&end_time, NULL);
		printf("%f\n", (double) ((end_time.tv_sec - start_time.tv_sec) 
				+ ((double) (end_time.tv_usec - start_time.tv_usec) / 1000000)));
	}
}
