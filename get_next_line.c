/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hna <hna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:45:40 by hna               #+#    #+#             */
/*   Updated: 2020/02/28 16:16:28 by hna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	static char	*buf;
	static int	start;
	char		*ret;
	int			i;
	static int	readn;

	if (!buf)
	{
//		printf("====buf init===\n");
		if(!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		buf[BUFFER_SIZE] = '\0';
//		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		readn = read(fd, buf, BUFFER_SIZE);
//		printf("readn: %d\n", readn);
	}
	if (!(ret = malloc(1)))
		return (-1);
	ret[0] = '\0';
//	printf("While Start\n");
//	printf("Init start: %d\n", start);
	i = start;
	while (i <= BUFFER_SIZE)
	{
//		printf("i: %d\n", i);
		if (i == BUFFER_SIZE)
		{
			ret = ft_strjoin_eol(ret, &buf[start]);
			i = -1;
			start = 0;
			readn = read(fd, buf, BUFFER_SIZE);
//			printf("buf init=====\n");
//			printf("readn: %d\n", readn);
//			printf("buf: %s\n", buf);
//			printf("===========\n");
		}
		if (readn == 0)
			return (0);
		if (buf[i] == '\n')
		{
//			printf("i: %d, readn: %d\n", i, readn);
			ret = ft_strjoin_eol(ret, &buf[start]);
			*line = ret;
			start = i + 1;
			return (1);
		}
		i++;
	}
	return (-1);
}

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**buf;
	char	*temp;
	int		ret;

	buf = &temp;
	if (argc || argv)
		printf("./get_next_line <file>\n");
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	while (get_next_line(fd, buf))
		printf("%s\n", *buf);
	free(*buf);
	close(fd);
	return(0);
}
