/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:18:09 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/27 13:14:50 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	print_char(char c);
int	print_string(char *s);
int	print_address(unsigned long long addr);
int	print_decimal(int nb);
int	print_unsigned_decimal(unsigned int nb);
int	print_hexadecimal(unsigned int nb, int flag);

#endif
