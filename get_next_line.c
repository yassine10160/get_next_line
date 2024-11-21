/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/21 19:32:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char    *ft_strdup(const char *s)
{
        int             i;
        char    *dest;
        int             len;

        if (!s)
                return (NULL);
        len = ft_strlen(s);
        dest = malloc((len + 1) * sizeof(char));
        if (!dest)
                return (NULL);
        i = 0;
        while (i < len)
        {
                dest[i] = s[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

char	*read_file(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char*		str;
	ssize_t		bytes;

	bytes = -2;
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, 0, 0) == -1)
		return (buff[0] = '\0', NULL);
	str = NULL;
	while (ft_index_line(buff) == -1 && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff, ft_index_line(buff) + 1);
		if (bytes == 0)
			return (str);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	if (ft_index_line(buff) != -1 && bytes == -2)
	{
		str = ft_strjoin(str, buff, ft_index_line(buff) + 1);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	return (str);
}
//je n ai pas la derniere ligne car il n y a pas de \n (modifier le if de read file)
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
	for (int i = 0; i < 4; i++)
	{
    	printf("-%s", dest);
		// free (dest);
    	dest = get_next_line(fd);
	}
    return (0);
}