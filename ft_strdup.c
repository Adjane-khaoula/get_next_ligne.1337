/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:25:34 by kadjane           #+#    #+#             */
/*   Updated: 2021/11/19 18:20:17 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
