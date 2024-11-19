/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:40:42 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/11/19 17:36:45 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	size_t	len1;
	size_t	len2;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
    __builtin_printf("%zu\n", len1);
	len2 = ft_strlen(s2);
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
    // __builtin_printf("%c\n", dest[0]);
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
char	*ft_strchr(const char *s, int c, int len)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && i < (size_t)len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}