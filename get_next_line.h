/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:48 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/22 14:12:03 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

char	*get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2, int index);
char	*ft_strchr(const char *s, int c);
size_t  ft_strlen(char const *s);
int     ft_index_line(char *s);
void    ft_reset(char *s, int end);
int	faux_strchr(const char *s, int c);

#endif