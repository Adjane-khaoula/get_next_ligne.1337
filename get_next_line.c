/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:40 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/17 20:57:13 by kadjane          ###   ########.fr       */
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
	int		i;

	i = -1;
	if (!*save)
		return (NULL);
	if (n == 0)
		position = ft_strlen(save);
	ligne = malloc(position + 1);
	if (!ligne)
		return (NULL);
	while (++i < position)
		ligne[i] = save[i];
	ligne[i] = '\0';
	return (ligne);
}

char	*ft_save(char *save, int n)
{
	char	*str;
	char	*pstr;
	int		position;
	char	*saveplus;

	if (n == 0)
		return (NULL);
	n = 1;
	position = ft_search(save);
	saveplus = save + position;
	str = malloc(ft_strlen(saveplus) + 1);
	if (!str)
		return (NULL);
	pstr = str;
	while (*saveplus)
		*str++ = *saveplus++;
	*str = '\0';
	return (pstr);
}

char	*ft_get_line(char *ligne, char **save, int n)
{
	char	*tmp;

	tmp = ft_ligne(ligne, ft_search(ligne), n);
	*save = ft_save(ligne, n);
	free(ligne);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*ligne;
	static char	*save;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read (fd, NULL, 0))
		return (NULL);
	if (!save)
		save = ft_strdup ("");
	ligne = ft_strdup(save);
	free(save);
	save = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = 1;
	while (n && ft_search(ligne) == 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		*(buff + n) = '\0';
		ligne = ft_strjoin(ligne, buff);
	}
	free(buff);
	return (ft_get_line(ligne, &save, n));
}

int main(int ac , char **av)
{
//	int fd;
	char *get = "hf\ngs"; 
	// fd = open("test/64bit_line.txt", O_CREAT |  O_RDWR, 0777);
	// write (fd, "anawr\nfe\n\n\n", 13);
	// close (fd);
//	fd = open(, O_RDONLY); 
	while (get != NULL)
	{
		get = get_next_line(0);
		printf("%s", get);
		free(get);
	}
	// system ("leaks a.out");
// 	// get = get_next_line(fd);
// 	// get = get_next_line(fd);
// 	// get = get_next_line(fd);
// 	// get = get_next_line(fd);
// 	// get = get_next_line(fd);	
// 	// printf("%d",ft_search(get));
}