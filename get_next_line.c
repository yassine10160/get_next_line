/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/11/25 16:04:46 by yafahfou         ###   ########.fr       */
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

char	*ft_strjoin_check(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2, ft_index_line(s2) + 1);
	if (s1)
		free(s1);
	return (tmp);
}

int	read_file(char *buff, char **str, int fd)
{
	ssize_t	bytes;

	bytes = -2;
	if (buff[0])
	{
		*str = ft_strjoin_check(*str, buff);
		if (!*str)
			return (-1);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	while (ft_index_line(*str) <= 0 && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			return (0);
		if (bytes == -1 || buff[0] == '\0')
			return (-1);
		if (bytes != 0)
			buff[bytes] = '\0';
		*str = ft_strjoin_check(*str, buff);
		if (!*str)
			return (-1);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "";
	char*		str;
	ssize_t		bytes;

	bytes = -2;
	if (BUFFER_SIZE <= 0 || fd == -1)
		return (buff[0] = '\0', NULL);
	str = NULL;
	bytes = read_file(buff, &str, fd);
	if (bytes == -1)
		return (NULL);
	else if (bytes == 0)
	{
		ft_reset(buff, ft_index_line(buff) + 1);
		return (str);
	}
	if (ft_index_line(buff) != -1 && bytes == -2 && ft_index_line(str) == -1)
	{
		str = ft_strjoin_check(str, buff);
		if (!str)
			return (NULL);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	return (str);
}

// char	*read_file(int fd)
// {
// 	static char	buff[BUFFER_SIZE + 1] = "";
// 	char*		str;
// 	char		*tmp;
// 	ssize_t		bytes;

// 	bytes = -2;
// 	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, 0, 0) == -1)
// 		return (buff[0] = '\0', NULL);
// 	str = NULL;
// 	while (ft_index_line(str) <= 0 && bytes != 0)
// 	{
// 		if (buff[0])
// 		{
// 			tmp = ft_strjoin(str, buff, ft_index_line(buff) + 1);
// 			if (str)
// 				free(str);
// 			str = tmp;
// 		}
// 		bytes = read(fd, buff, BUFFER_SIZE);
// 		if (bytes == 0)
// 			return (str);
// 		if (bytes == -1 || buff[0] == '\0')
// 			return (NULL);
// 		if (bytes != 0)
// 			buff[bytes] = '\0';
// 		tmp = ft_strjoin(str, buff, ft_index_line(buff) + 1);
// 		if (str)
// 			free(str);
// 		str = tmp;
// 		ft_reset(buff, ft_index_line(buff) + 1);
// 	}
// 	if (ft_index_line(buff) != -1 && bytes == -2)
// 	{
// 		str = ft_strjoin(str, buff, ft_index_line(buff) + 1);
// 		ft_reset(buff, ft_index_line(buff) + 1);
// 	}
// 	return (str);
// }

// gagner des lignes pour pouvoir bien free le strjoin
//je n ai pas la derniere ligne car il n y a pas de \n (modifier le if de read file)
// char	*get_next_line(int fd)
// {
// 	// char	*file;

// 	// file = read_file(fd);
// 	// return (file);
// 	return (read_file(fd));
// }

#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    char    *dest;
    int     fd;

    fd = open(av[1], O_RDONLY);
    dest = get_next_line(fd);
	while (dest)
	{
    	printf("-%s", dest);
		free (dest);
    	dest = get_next_line(fd);
	}
    return (ac * 0);
}