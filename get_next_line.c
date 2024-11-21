/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/20 19:26:58 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char*		str = NULL;
	ssize_t		bytes;

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
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*ft_line(char *s)
{
	int		i;
	char	*dest;

	dest = malloc(ft_index_line(s) + 1);
	i = 0;
	while (s && s[i] && s[i - 1] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}
char	*get_next_line(int fd)
{
	char	*file;
	char	*dest;

	file = read_file(fd);
	dest = ft_line(file);
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
	for (int i = 0; i < 3; i++)
	{
    	dest = get_next_line(fd);
    	printf("%s", dest);
		free (dest);
	}
    return (0);
}