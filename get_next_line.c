/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/21 16:22:24 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char*		str;
	ssize_t		bytes;

	bytes = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, 0, 0) == -1)
		return (buff[0] = '\0', NULL);
	str = NULL;
	while (ft_index_line(buff) == -1 && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			return (str);
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff, ft_index_line(buff));
		ft_reset(buff);
		printf("str = |%s\n|",	 str);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*file;

	file = read_file(fd);
	return (file);
}

#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    char    *dest;
    int     fd;

    (void)ac;
	(void)dest;
    fd = open(av[1], O_RDONLY);
    dest = get_next_line(fd);
	for (int i = 0; i < 3; i++)
	{
    	printf("-%s", dest);
		// free (dest);
    	dest = get_next_line(fd);
	}
    return (0);
}