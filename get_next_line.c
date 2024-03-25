/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:16:54 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/25 09:10:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		*buffer_readed;
	int			bytes_readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("\nReading\n");
	buffer_readed = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer_readed == NULL)
		return (NULL);
	bytes_readed = 1;
	while (!ft_strchr(stash, '\n') && bytes_readed != 0)
	{
		bytes_readed = read(fd, buffer_readed, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buffer_readed);
			free(stash);
            return (NULL);
		}
		stash = ft_strjoin(stash, buffer_readed);
	}
	free(buffer_readed);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}
