/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/19 15:52:05 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	char	*buff;
	ssize_t	bytes;

    buff = NULL;
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd,0,0) == -1)
		return (buff[0] = '\0', NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	// __builtin_printf("%s\n", buff);
	return(buff);
}

char	*get_next_line(int fd)
{
	char	*dest;

	dest = read_file(fd);
	dest = ft_strchr(dest, '\n', BUFFER_SIZE);
	return (dest);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(int ac, char **av)
// {
//     char    *dest;
//     int     fd;

//     (void)ac;
//     fd = open(av[1], O_RDONLY);
//     dest = get_next_line(fd);
//     printf("%s", dest);
//     return (0);
// }