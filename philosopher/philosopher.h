/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:17:47 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/28 16:35:56 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>

enum e_philo_state
{
	THINKING,
	HUNGRY,
	EATING
};

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
	enum e_philo_state	*state;
	pthread_mutex_t		*fork;
	t_option			*opt;
	int					seq;
}	t_philo_identity;


int	ft_atoi(char *str);

#endif
