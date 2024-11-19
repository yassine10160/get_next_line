/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/19 17:42:49 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*str;
	ssize_t	bytes;

	bytes = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, 0, 0) == -1)
		return (buff[0] = '\0', NULL);
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			return (str);
		buff[BUFFER_SIZE] = '\0';
		str = ft_strjoin(str, buff);
		__builtin_printf("je suis la\n");
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*dest;

	dest = read_file(fd);
	return (dest);
}

#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    char    *dest;
    int     fd;

    (void)ac;
    fd = open(av[1], O_RDONLY);
    dest = get_next_line(fd);
    printf("%s", dest);
    return (0);
}