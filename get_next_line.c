/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:40 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/14 16:51:57 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search(char *ligne)
{
	int	position;

	position = 0;
	if (!ligne)
		return (0);
	while (*ligne)
	{		
		position++;	
		if (*ligne == '\n')
			return (position);	
		ligne++;	
	}
	return (0);
}

char	*ft_ligne(char *buff, int position)
{
	char	*ligne;
	char	*pligne;
	int		i;

	i = -1;
	ligne = malloc (position + 1);
	pligne = ligne;
	while (++i < position)
		*ligne++ = *buff++;
	*ligne = '\0';
	return (pligne);
}

char	*ft_save(char *str)
{
	char	*save;
	char	*psave;

	save = malloc(ft_strlen(str) + 1);
	psave = save;
	while (*str)
		*save++ = *str++;
	*save = '\0';
	return (psave);
}

char *get_next_line(int fd)
{
	char		*buff;
	char		*ligne;
	static char	*save;
	int			n;

	if (!save)
		save = ft_strdup ("");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = 1;
	while (n != 0 && ft_search(save) == 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		*(buff + n) = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	ligne = ft_ligne(save, ft_search(save));
	save = ft_save(save + ft_search(save));
	return (ligne);
}

int main(int ac , char **av)
{
	int fd;
	char *get = "hf\ngs"; 
	
	fd = open("test.txt", O_CREAT |  O_RDWR, 0777);
	write (fd, "khawlaadj\nanawr\nfe", ft_strlen("khawlaadj\n\nanawr\nfe"));
	close (fd);
	fd = open("test.txt", O_RDONLY); 
	get = get_next_line(fd);
	get = get_next_line(fd);
	get = get_next_line(fd);
	// get = get_next_line(fd);
	// get = get_next_line(fd);
	// get = get_next_line(fd);
	// get = get_next_line(fd);
	printf("%s", get);
	// printf("%d",ft_search(get));
}