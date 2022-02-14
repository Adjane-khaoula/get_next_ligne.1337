/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:01:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/14 14:25:17 by kadjane          ###   ########.fr       */
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

	if (!s1)
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
