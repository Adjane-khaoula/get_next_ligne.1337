/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:40 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/09 19:10:35 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	else
	{
		while (str[i])
			i++;
	}
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

	if (s1 == NULL)
		return (ft_strdup((char *)s2));
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

int		ft_search(char *ligne)
{
	int position;

	position = 0;
	if (!ligne)
		return (0);
	while (*ligne++)
	{
		position++;
		if (*ligne == '\n')
		return (poition);
	}
	return (0);
}

char	ft_ligne(char *buff, int position)
{
	char	*ligne;
	int		i;

	i = 0;
	while (i++ <= position)
		*ligne++ = *buff++;
	return (ligne);
}

char	ft_save(char *str)
{
	char 	*save;
	while (*str)
		*save++ = *str++;
	*save = '\0';
	return (save); 
}

char *get_next_line(int fd)
{
	char		*buff;
	char		*ligne;
	static char	*save = NULL;
	int			n;
	int			searchinsave;
	int			searchinbuff;

	searchinsave = ft_search(save);
	if (searchinsave != 0)
	{
		ligne = ft_ligne(save, searchinsave);
		save = ft_save(save + searchinsave + 1);
		retun (ligne);
	}
	while (1)
	{
		buff = malloc(ft_strlen (save) + BUFFER_SIZE + 1);
		n = read (fd, buff, BUFFER_SIZE);
		*(buff + (ft_strlen (save) + BUFFER_SIZE + 1)) = '\0';
		buff = ft_strjoin(save,buff);
		searchinbuff = ft_search(buff);
		if (searchinbuff != 0) 
		{
			ligne = ft_ligne(buff, searchinbuff);
			save = ft_save(buff + searchinbuff + 1);
		}
		if (n == 0 || n == -1 || searchinbuff != 0)
			break ;
	}
}

int main(int ac , char **av)
{
	int fd;
	// char *get;

	// fd = open("test.txt", O_CREAT |  O_RDWR, 0777);
	// write (fd, "khawlaadjane",12);
	// close (fd);
	// fd = open("test.txt", O_RDONLY); 
	// get = get_next_line(fd);
	fd = ft_strlen("abs\nhs");
	printf("%d",fd);
}