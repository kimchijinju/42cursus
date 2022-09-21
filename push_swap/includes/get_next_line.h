/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:04:19 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 11:36:29 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	struct s_list	*next;
	int				fd;
	char			*backup;
}	t_list;

char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
char	*ft_list_remove_if(t_list **begin_list, int fd);

#endif
