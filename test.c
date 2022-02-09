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

{
		j = 0;
		buff = malloc(ft_strlen(save) + BUFFER_SIZE + 1);
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = 0;
		buff = ft_strjoin(save,buff);
		ligne = malloc (ft_strlen(save) + ft_strlen(buff) + 1);
		while (buff[j] != '\0' && buff[j] != '\n')
			ligne[i++] = buff[j++];
		if (n == 0 || n == -1 || buff[j] == '\n')
			break ;
	} 
	ligne[i + 1] = '\0';
	while (*buff == '\n')
		buff++;
	save = malloc(ft_strlen(buff) + 1);
	while (*buff)
		*save++ = *buff++;
	*save = '\0';
	return (ligne);