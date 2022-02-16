/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:43:56 by kadjane           #+#    #+#             */
/*   Updated: 2022/02/16 16:50:42 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *save, char *buff);
int		ft_search(char *ligne);
char	*ft_ligne(char *buff, int position, int n);
char	*ft_save(char *save, int n);
char	*ft_get_line(char **ligne,char **save);
char	*get_next_line(int fd);

#endif