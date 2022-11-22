/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:04:19 by hanbkim           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:50 by hanbkim          ###   ########.fr       */
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

char	*ft_strjoin_vergnl(char *s1, char const *s2);
char	*ft_strdup_vergnl(const char *s1);
void	*ft_memmove_vergnl(void *dst, const void *src, size_t len);
size_t	ft_strlen_vergnl(const char *str);
void	*ft_memset_vergnl(void *b, int c, size_t len);
char	*ft_list_remove_if_vergnl(t_list **begin_list, int fd);

#endif
