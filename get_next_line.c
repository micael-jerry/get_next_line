/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:54 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/25 07:44:54 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct buffer_read_s
{
	int		bytes_read;
	char	*buffer;
} buffer_read_t;

static buffer_read_t	buffer_read(int fd)
{
	buffer_read_t    buffer_readed;

	buffer_readed.buffer = NULL;
	buffer_readed.bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buffer_readed);
	buffer_readed.buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_readed.buffer)
		return (buffer_readed);
	buffer_readed.bytes_read = read(fd, buffer_readed.buffer, BUFFER_SIZE);
	if (buffer_readed.bytes_read <= 0)
	{
		free(buffer_readed.buffer);
		buffer_readed.buffer = NULL;
		buffer_readed.bytes_read = 0;
	}
	return (buffer_readed);
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

static size_t	find_next_line_break(char *str, size_t i)
{
	char	*ptr;

	ptr = str + i;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (ptr - str);
}

static char *get_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash || *stash == '\0')
		return (NULL);
	i = find_next_line_break(stash, i);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(stash + i) && *(stash + i) != '\n')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	if (*(stash + i) == '\n')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}
static char	*get_stash(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*buffer)
		return (free(buffer), NULL);
	i = find_next_line_break(buffer, i);
	new_buffer = (char *)malloc((ft_strlen(buffer) - i) + 1);
	if (!new_buffer)
		return (free(new_buffer), NULL);
	while (*(buffer + i))
		*(new_buffer + j++) = *(buffer + i++);
	*(new_buffer + j) = '\0';
	if (!*new_buffer)
		return (free(buffer), free(new_buffer), NULL);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	buffer_read_t	buffer_readed;
	char		*line;

	while (1 == 1)
	{
		buffer_readed = buffer_read(fd);
		if (buffer_readed.bytes_read == -1)
		{
			free(stash);
            return (NULL);
		}
		else if (ft_strchr(stash, '\n') && buffer_readed.bytes_read == 0)
			break ;
		stash = ft_strjoin(stash, buffer_readed.buffer);
	}
	free(buffer_readed.buffer);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}
