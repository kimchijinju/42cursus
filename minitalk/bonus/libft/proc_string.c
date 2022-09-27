/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:16:17 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/02 11:53:37 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	print_string(char *s)
{
	int	w_len;

	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	w_len = strlen(s);
	return (write(STDOUT_FILENO, s, w_len));
}

int	print_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
