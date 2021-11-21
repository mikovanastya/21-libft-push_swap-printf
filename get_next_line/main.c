
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
 int  fd;

 fd = open("text.txt", O_RDONLY);
 int fd1 = open("text1.txt", O_RDONLY);
 printf("%s", get_next_line(fd));
 printf("2)%s", get_next_line(fd1));
 printf("2)%s", get_next_line(fd1));
 printf("%s", get_next_line(fd));
 printf("%s", get_next_line(fd));
 
 close(fd);
 close(fd1);
 return (0);
}
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*str;

	fd = open("get_next_line.c", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}