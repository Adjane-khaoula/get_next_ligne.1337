/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:01:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/17 20:53:51 by kadjane          ###   ########.fr       */
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
	if (!p)
		return (NULL);
	p2 = p;
	while (src[i])
	{
		*p = src[i];
		p++;
		i++;
	}
	*p = '\0';
	return (p2);
}

char	*ft_strjoin(char *ligne, char *buff)
{
	char	*stock;
	char	*pstock;
	char	*pligne;

	if (!(*ligne))
	{
		free(ligne);
		return (ft_strdup(buff));
	}
	stock = malloc(ft_strlen(ligne) + ft_strlen(buff) + 1);
	if (!stock)
		return (NULL);
	pstock = stock;
	pligne = ligne;
	while (*ligne)
		*stock++ = *ligne++;
	while (*buff)
		*stock++ = *buff++;
	*stock = '\0';
	free(pligne);
	return (pstock);
}
