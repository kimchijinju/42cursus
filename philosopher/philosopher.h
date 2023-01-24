/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:17:47 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 16:36:51 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_option
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_option;

typedef	struct s_philo_identity
{
	pthread_mutex_t		*m_fork;
	pthread_mutex_t		*m_died;
	t_option			*opt;
	struct timeval		*last_eat_time;
	bool				who_died;
	int					seq;
	struct timeval		start_time;
	struct timeval		log_time;
}	t_philo_identity;


int	ft_atoi(char *str);

// time.c
void	msleep(int time);
double	get_millisecond(struct timeval time);

#endif
