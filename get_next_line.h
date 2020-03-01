/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <hna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:43:38 by hna               #+#    #+#             */
/*   Updated: 2020/03/01 21:05:25 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_buffer
{
	int		start_idx;
	int		cur_idx;
	int		read_n;
	char	buf[BUFFER_SIZE + 1];
}				t_buffer;

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat_eol(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin_eol(char *s1, char *s2);

#endif
