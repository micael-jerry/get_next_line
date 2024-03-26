/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:17:19 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/26 21:58:47 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if ((int)str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	return (str);
}
