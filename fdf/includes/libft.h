/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:07:40 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:55 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_atoi(const char *str);
int		ft_atoi_hexa(const char *str);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	free_split(char **s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
void	error_handling(const char	*errname);
int		ft_abs(int a);
char	*get_next_line(int fd);

#endif
