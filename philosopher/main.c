/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 16:36:20 by hanbkim          ###   ########.fr       */
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
	time = get_millisecond(_this->log_time) - get_millisecond(_this->start_time);
	printf("%.0f %d %s\n", time, _this->seq, log);
}

bool	philosopher_starvation(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1) % _this->opt->number_of_philosophers;

	pthread_mutex_lock(_this->m_died);
	if (_this->who_died == false)
	{
		pthread_mutex_unlock(_this->m_died);
		return (false);
	}
	if (_this->seq % 2 == 0)
	{
		pthread_mutex_unlock(&_this->m_fork[left]);
		pthread_mutex_unlock(&_this->m_fork[right]);
	}
	else
	{
		pthread_mutex_unlock(&_this->m_fork[right]);
		pthread_mutex_unlock(&_this->m_fork[left]);
	}
	pthread_mutex_unlock(_this->m_died);
	return (true);
}

bool	think(t_philo_identity *_this)
{
	if (philosopher_starvation(_this) == true)
		return (false);
	print_log(_this, "is thinking");
	return (true);
}

bool	take_up_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1) % _this->opt->number_of_philosophers;

	if (_this->seq % 2 == 0)
	{
		pthread_mutex_lock(&_this->m_fork[left]);
		pthread_mutex_lock(&_this->m_fork[right]);
	}
	else
	{
		pthread_mutex_lock(&_this->m_fork[right]);
		pthread_mutex_lock(&_this->m_fork[left]);
	}
	if (philosopher_starvation(_this) == true)
		return (false);
	print_log(_this, "has taken a fork");
	return (true);
}

bool	eat_spaghetti(t_philo_identity *_this)
{
	msleep(_this->opt->time_to_eat);
	gettimeofday(&_this->last_eat_time[_this->seq], NULL);
	if (philosopher_starvation(_this) == true)
		return (false);
	print_log(_this, "is eating");
	return (true);
}

void	take_down_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1) % _this->opt->number_of_philosophers;

	if (_this->seq % 2 == 0)
	{
		pthread_mutex_unlock(&_this->m_fork[left]);
		pthread_mutex_unlock(&_this->m_fork[right]);
	}
	else
	{
		pthread_mutex_unlock(&_this->m_fork[right]);
		pthread_mutex_unlock(&_this->m_fork[left]);
	}
	msleep(_this->opt->time_to_sleep);
}

void	*philosopher_life_cycle(void *arg)
{
	t_philo_identity	*_this;

	_this = (t_philo_identity *)arg;
	while (1)
	{
		if (think(_this) == false)
			break ;
		if (take_up_fork(_this) == false)
			break ;
		if (eat_spaghetti(_this) == false)
			break ;
		take_down_fork(_this);
	}
	return (NULL);
}

void	died_flag_on(t_philo_identity *philosophers, int number_of_philosophers)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philosophers->m_died);
	while(i < number_of_philosophers)
	{
		philosophers[i].who_died = true;
		++i;
	}
	pthread_mutex_unlock(philosophers->m_died);
}

void	monitering_philosophers(t_philo_identity *philosophers, pthread_t *thread)
{
	const double	deadline = philosophers->opt->time_to_die;
	double			last_eat_time;
	struct timeval	cur_time;
	bool			die;
	int				i;

	while(1)
	{
		i = 0;
		die = false;
		while (i < philosophers->opt->number_of_philosophers)
		{
			gettimeofday(&cur_time, NULL);
			last_eat_time = get_millisecond(cur_time) - get_millisecond(philosophers[i].last_eat_time[i]);
			if (last_eat_time > deadline)
			{
				died_flag_on(philosophers, philosophers->opt->number_of_philosophers);
				die = true;
				print_log(&philosophers[i], "died");
				break ;
			}
			++i;
		}
		if (die == true)
			break ;
	}

	int status;
	i = 0;
	while (i < philosophers->opt->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
	while (i < philosophers->opt->number_of_philosophers)
	{
		pthread_mutex_destroy(&(philosophers->m_fork[i]));
		++i;
	}
	i = 0;
	pthread_mutex_destroy(philosophers->m_died);
}

void	birth_philosopher(t_option *opt)
{
	t_philo_identity	*philosophers;
	pthread_t			*thread;
	pthread_mutex_t		*m_fork;
	pthread_mutex_t		*m_died;
	struct timeval		*last_eat_time;
	bool				who_died;
	int					i;

	// malloc guard
	thread = malloc(sizeof(pthread_t) * opt->number_of_philosophers);
	philosophers = malloc(sizeof(t_philo_identity) * opt->number_of_philosophers);
	m_fork = malloc(sizeof(pthread_mutex_t) * opt->number_of_philosophers);
	m_died = malloc(sizeof(pthread_mutex_t));
	last_eat_time = malloc(sizeof(struct timeval) * opt->number_of_philosophers);
	pthread_mutex_init(m_died, NULL);
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		pthread_mutex_init(&(m_fork[i]), NULL);
		++i;
	}
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		philosophers[i].m_fork = m_fork;
		philosophers[i].m_died = m_died;
		philosophers[i].seq = i;
		philosophers[i].opt = opt;
		philosophers[i].last_eat_time = last_eat_time;
		philosophers[i].who_died = false;
		gettimeofday(&philosophers[i].start_time, NULL);
		gettimeofday(&philosophers[i].last_eat_time[i], NULL);
		pthread_create(&thread[i], NULL, philosopher_life_cycle, &philosophers[i]);
		++i;
	}
	monitering_philosophers(philosophers, thread);
}

int main(int argc, char **argv)
{
	t_option	opt;

	if (argc != 5 && argc != 6)
		return (1);
	init_argment(&opt, argc, argv);
	birth_philosopher(&opt);
}

