/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:54 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/24 22:32:11 by mfidimal         ###   ########.fr       */
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

void    *ft_memcpy(void *dest, const void *src, size_t size)
{
        unsigned char           *result;
        const unsigned char     *source;
        size_t                          i;

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
	int	i;
	char	*return_val;

	str = ft_strchr(buffer, '\n') + 1;
	i = 0;
	return_val = ft_calloc(ft_strlen(str, '\0') + 1, sizeof(char));
	if (!return_val)
		return (NULL);
	ft_memcpy(return_val, str, ft_strlen(str, '\0'));
	return (return_val);
}

char	*get_next_line(int fd)
{
	static char	*stash = "";
	char		*buffer;
	char		*line;

	while (1 == 1)
	{
		buffer = buffer_read(fd);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
		stash = ft_strjoin(stash, buffer, '\0');
	}
	line = ft_strjoin(stash, buffer, '\n');
	stash = NULL;
	stash = get_stash(buffer);
	free(buffer);
	return (line);
}
