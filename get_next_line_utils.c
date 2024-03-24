/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:17:19 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/24 21:49:56 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, char last_chr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == last_chr)
			break;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str, '\0');
	i = 0;
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

char	*ft_strjoin(char const *s1, char const *s2, char last_chr)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1, '\0') + ft_strlen(s2, '\n') + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		if (s2[j] == last_chr)
			break;
		j++;
	}
	str[i] = '\0';
	return (str);
}
