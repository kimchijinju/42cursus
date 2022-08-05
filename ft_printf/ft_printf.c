/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:07:11 by hanbkim           #+#    #+#             */
/*   Updated: 2022/08/02 11:37:47 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	args_proc(va_list ap, char c)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	else if (c == 's')
		return (print_string(va_arg(ap, char *)));
	else if (c == 'p')
		return (print_address(va_arg(ap, unsigned long long)));
	else if (c == 'd')
		return (print_decimal(va_arg(ap, int)));
	else if (c == 'i')
		return (print_decimal(va_arg(ap, int)));
	else if (c == 'u')
		return (print_unsigned_decimal(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (print_hexadecimal(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (print_hexadecimal(va_arg(ap, unsigned int), 1));
	else if (c == '%')
		return (print_char('%'));
	return (-1);
}

int	write_logic(const char *s, va_list ap)
{
	int	print_bytes;
	int	check_bytes;

	print_bytes = 0;
	check_bytes = 0;
	while (*s)
	{
		if (*s == '%')
			check_bytes = args_proc(ap, *(++s));
		else
			check_bytes = write(STDOUT_FILENO, s, 1);
		if (check_bytes < 0)
			return (-1);
		print_bytes += check_bytes;
		s++;
	}
	return (print_bytes);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		print_bytes;

	va_start(ap, s);
	print_bytes = write_logic(s, ap);
	va_end(ap);
	return (print_bytes);
}
