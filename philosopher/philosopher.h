/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:17:47 by hanbkim           #+#    #+#             */
/*   Updated: 2023/02/03 13:50:21 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define TABLE 0
# define HAND 1

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
	bool			*fork_state;
	pthread_mutex_t	m_died;
	pthread_mutex_t	m_last_eat_time;
	pthread_mutex_t	m_philo_must_eat;
	t_option		*opt;
	bool			who_died;
}	t_shared_variable;

typedef struct s_philo_identity
{
	t_shared_variable	*shared;
	long				start_time;
	int					philo_must_eat;
	long				last_eat_time;
	bool				eat_done;
	int					seq;
}	t_philo_identity;

bool	valid_argment(int argc, char **argv);
void	init_argment(t_option *opt, int argc, char **argv);

void	monitering_philosophers(t_philo_identity *philosophers);
bool	who_is_died(t_philo_identity *philosophers);
void	wait_thread(t_shared_variable *shared, pthread_t *thread);

bool	birth_philosopher(t_option *opt,
			t_philo_identity **philosophers, pthread_t **thread);

void	*philosopher_life_cycle(void *arg);
bool	solo_philosopher(t_philo_identity *_this);
bool	philosopher_starvation(t_philo_identity *_this,
			bool left_fork_use, bool right_fork_use);
bool	take_up_fork(t_philo_identity *_this);
bool	take_down_fork(t_philo_identity *_this);

int		ft_atoi(char *str);
void	print_log(t_philo_identity *_this, char *log);
void	msleep(int time);
long	get_millisecond(void);

#endif
