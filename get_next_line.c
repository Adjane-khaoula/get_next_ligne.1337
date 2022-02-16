/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:40 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/16 19:00:25 by kadjane          ###   ########.fr       */
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

char	*ft_ligne(char *save, int position, int n)
{
	char	*ligne;
	char	*pligne;
	int		i;

	i = -1;
	if (!*save)
		return (NULL);
	if (n == 0)
		position = ft_strlen(save);
	ligne = malloc (position + 1);
	if (!ligne)
		return (NULL);
	pligne = ligne;
	while (++i < position)
		*ligne++ = *save++;
	*ligne = '\0';
	return (pligne);
}

char	*ft_save(char **save, int n)
{
	char	*str;
	char	*psave;
	int		position;

	if (n == 0)
		return (NULL);
	position = ft_search(*save);
	str = malloc(ft_strlen(save + position) + 1);
	if (!str)
		return (NULL);
	psave = str;
	while (*str)
		*str++ = *(save++ + position);
	*str = '\0';
	return (psave);
}

char	ft_get_line(char **line,char **save, int n)
{
	char	*tmp;
	

	tmp = ft_ligne(*save, ft_search(*save), n);
	save = ft_save(*save, n);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*ligne;
	static char	*save;
	char		*stock;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, NULL, 0))
		return (NULL);
	if (!save)
		save = ft_strdup ("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = 1;
	while (n && ft_search(save) == 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		*(buff + n) = '\0';
		stock = ft_strjoin(save, buff);
		save = stock;
	}
	free(buff);
	return (ft_get_line(&save, n);
}

// int main(int ac , char **av)
// {
// 	int fd;
// 	char *get = "hf\ngs"; 
// 	// fd = open("test/64bit_line.txt", O_CREAT |  O_RDWR, 0777);
// 	// write (fd, "anawr\nfe\n\n\n", 13);
// 	// close (fd);
// 	fd = open("test/64bit_paragraph.txt", O_RDONLY); 
// 	while (get != NULL)
// 	{
// 		get = get_next_line(fd);
// 		printf("%s", get);
// 		//free(get);
// 	}
// 	system ("leaks a.out");
// // 	// get = get_next_line(fd);
// // 	// get = get_next_line(fd);
// // 	// get = get_next_line(fd);
// // 	// get = get_next_line(fd);
// // 	// get = get_next_line(fd);	
// // 	// printf("%d",ft_search(get));
// }