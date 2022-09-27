/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:13:50 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/27 13:38:08 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_atoi(char *str);

typedef struct s_reciver
{
	int	byte;
	int	bit_count;
}	t_reciver;

#endif
