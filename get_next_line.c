/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:54 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/25 06:10:29 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buffer_read(int fd)
{
	int		bytes_read;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*result;
	const unsigned char	*source;
	size_t				i;

	result = dest;
	source = src;
	i = 0;
	if (dest == src || !size)
		return (dest);
	while (i < size)
	{
		result[i] = source[i];
		i++;
	}
	return (dest);
}

static char	*get_stash(char *buffer)
{
	char	*str;
	char	*return_val;

	str = ft_strchr(buffer, '\n') + 1;
	return_val = ft_calloc(ft_strlen(str, '\0') + 1, sizeof(char));
	if (!return_val)
		return (NULL);
	ft_memcpy(return_val, str, ft_strlen(str, '\0'));
	return (return_val);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buffer;
	char		*line;

	while (1 == 1)
	{
		buffer = buffer_read(fd);
		if (!stash && buffer)
			stash = "";
		else if (ft_strchr(buffer, '\n') || (ft_strchr(stash, '\n') && !buffer))
			break ;
		else if (!buffer)
			return (NULL);
		stash = ft_strjoin(stash, buffer, '\0');
	}
	if (ft_strchr(stash, '\n') && !buffer)
	{
		line = ft_strjoin("", stash, '\n');
		buffer = stash;
	}
	else
		line = ft_strjoin(stash, buffer, '\n');
	// free(stash);
	stash = get_stash(buffer);
	free(buffer);
	return (line);
}
