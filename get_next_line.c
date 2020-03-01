/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <hna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:45:40 by hna               #+#    #+#             */
/*   Updated: 2020/03/01 17:42:18 by hna              ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	start;
	char		*ret;
	int			i;
	static int	readn;


	if (!(ret = malloc(1)) || fd < 0)
		return (-1);
	i = start;
	if (*buf == 0)
		readn = read(fd, buf, BUFFER_SIZE);
	if (readn < 0)
		return (-1);
	ret[0] = '\0';
	while (buf[i] != '\n' && readn != 0)
	{
		if (i == BUFFER_SIZE)
		{
			ret = ft_strjoin_eol(ret, &buf[start]);
			i = -1;
			start = 0;
			ft_memset((void *)buf, 0, BUFFER_SIZE + 1);
			readn = read(fd, buf, BUFFER_SIZE);
		}
		i++;
	}
	if (readn == 0)
	{
		*line = ret;
		return (0);
	}
	ret = ft_strjoin_eol(ret, &buf[start]);
	*line = ret;
	start = i + 1;
	return (1);
}
