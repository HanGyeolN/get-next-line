/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <hna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:45:40 by hna               #+#    #+#             */
/*   Updated: 2020/03/01 21:31:42 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *arr, int c, size_t len)
{
	unsigned char	*p = arr;

	while (len > 0)
		p[--len] = c;
	return (arr);
}

/*
char	*get_line(int fd, char **line)
{
*/

int		get_next_line(int fd, char **line)
{
	static t_buffer	buffer;
	char			*ret;

	if (!(ret = malloc(1)) || fd < 0)
		return (-1);
	buffer.cur_idx = buffer.start_idx;
	if (buffer.buf[0] == 0)
		buffer.read_n = read(fd, buffer.buf, BUFFER_SIZE);
	if (buffer.read_n < 0)
	{
		free(ret);
		return (-1);
	}
	ret[0] = '\0';
	while (buffer.buf[buffer.cur_idx] != '\n' && buffer.read_n > 0)
	{
		if (buffer.cur_idx == BUFFER_SIZE)
		{
			ret = ft_strjoin_eol(ret, &(buffer.buf[buffer.start_idx]));
			buffer.cur_idx = -1;
			buffer.start_idx = 0;
			ft_memset((void *)buffer.buf, 0, BUFFER_SIZE + 1);
			buffer.read_n = read(fd, buffer.buf, BUFFER_SIZE);
		}
		buffer.cur_idx++;
	}
	*line = ret;
	if (buffer.read_n == 0)
		return (0);
	ret = ft_strjoin_eol(ret, &(buffer.buf[buffer.start_idx]));
	*line = ret;
	buffer.start_idx = buffer.cur_idx + 1;
	return (1);
}
