#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int fd;
	int r;
	char *buff;

	buff = malloc(13);

	//write

	fd = open("adjane.txt",O_CREAT | O_RDWR,0600);
	write(fd, "hello worldasdfg!\n", 13);
	 close(fd);

	//read
	fd = open("adjane.txt",O_RDONLY);
	r = read(fd, buff,13);
	printf("%d\n",r);
	printf("%s",buff);
	close (fd);


	// buff[13] = '\0';
	// fd = open(av[1], O_RDONLY);
	// while(1)
	// {
	// 	r = read(fd,buff,1);
	// 	buff[r]= '\0';
	// 	//printf("%d\n",r);
	// 	printf("%s",buff);
	// 	if (r == 0)
	// 		break ;
	// }
}