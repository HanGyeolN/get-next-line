#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	fd = open(argv[1], O_RDONLY);
	read(fd, buf, BUFFER_SIZE);
	write(1, buf, BUFFER_SIZE);

	close(fd);
	return (0);
}
