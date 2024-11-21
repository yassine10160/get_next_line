/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:42 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/11/21 16:18:24 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, int index)
{
	char	*dest;
	int		i;
	size_t	len1;
	size_t	len2;
	int		j;

	len1 = ft_strlen(s1);
	if (index == -1)
		len2 = ft_strlen(s2);
	else
		len2 =  (ft_strlen(s2)) - (ft_strlen(s2) - index);
	i = 0;
	dest = malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && (size_t)j < len2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
int	ft_index_line(char *s)
{
	int	i = 0;

	while (s && s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}
size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

void	ft_reset(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strchr(s, '\n');
	if (str)
	{
		while (str[++i])
			s[i] = str[i];
	}
	while (s && s[i])
		s[i++] = '\0';
}
