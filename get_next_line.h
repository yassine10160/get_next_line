/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:48 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/19 15:41:14 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

char	*get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c, int len);
size_t  ft_strlen(char const *s);

#endif