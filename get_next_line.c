/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:40 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/07 23:47:34 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*p;
	char	*p2;

	i = 0;
	l = ft_strlen(src) + 1;
	p = (char *)malloc(l);
	p2 = p;
	if (p == 0)
		return (0);
	while (src[i])
	{
		*p = src[i];
		p++;
		i++;
	}
	*p = '\0';
	return (p2);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s; 
	char	*ps;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	ps = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (ps);
}

char *get_next_line(int fd)
{
	char		*buff;
	char		*ligne;
	static char	*save;
	int			nbit;

	save = ft_strdup("");
	
	while (1)
	{
		nbit = read (fd, buff, BUFFER_SIZE);
		buff = ft_strjoin(save,buff);
		ligne = malloc (ft_strlen(save) + ft_strlen(buff) + 1);
		while (*buff++ && *buff++ != '\n' )
			*ligne = *buff;
		if (nbit == 0 || nbit == -1 || *buff == '\n')
			break ;
	} 
	*ligne = '\0';
	while (*buff == '\n')
		buff++;
	save = malloc(ft_strlen(buff) + 1);
	while (*buff)
		*save++ = *buff++;
	*save = '\0';	
	return (ligne);
} 

int main(int ac , char **av)
{
	int fd;
	char *get;
	
	fd = open("test.txt", O_CREAT |  O_RDWR, 0777);
	write (fd, "khawlaadjane",12);
	close (fd);
	fd = open("test.txt", O_RDONLY); 
	get = get_next_line(fd);
	printf("%s",get);
}