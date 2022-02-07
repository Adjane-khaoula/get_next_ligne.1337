/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:11:05 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/06 13:01:23 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

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

	// if (!s1)
	// 	return (ft_strdup((char *)s2));
	// if (!s2)
	// 	return (ft_strdup((char *)s1));
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
int main()
{
	char *s;
	s = ft_strjoin("","adjane");
	printf("%s\n",s);
}