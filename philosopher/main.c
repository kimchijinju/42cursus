/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:18:41 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 14:46:47 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_option			opt;
	t_philo_identity	*philosophers;
	pthread_t			*thread;

	if (argc != 5 && argc != 6)
		return (1);
	if (valid_argment(argc, argv) == false)
		return (1);
	init_argment(&opt, argc, argv);
	if (birth_philosopher(&opt, &philosophers, &thread) == false)
		return (1);
	monitering_philosophers(philosophers);
	wait_thread(philosophers->shared, thread);
	return (0);
}
