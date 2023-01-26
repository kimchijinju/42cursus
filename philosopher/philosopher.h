/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:17:47 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/26 16:26:57 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_option
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_option;

typedef struct s_shaerd_variable
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_died;
	t_option		*opt;
	double			*last_eat_time;
	bool			who_died;
}	t_shared_variable;

typedef struct s_philo_identity
{
	t_shared_variable	*shared;
	double				start_time;
	int					philo_must_eat;
	int					seq;
}	t_philo_identity;

int		ft_atoi(char *str);
void	print_log(t_philo_identity *_this, char *log);
void	*philosopher_life_cycle(void *arg);
void	monitering_philosophers(t_philo_identity *philosophers);
void	wait_and_destory(t_shared_variable *shared, pthread_t *thread);
void	msleep(double time);
double	get_millisecond();

#endif
