/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:12:22 by mfidimal          #+#    #+#             */
/*   Updated: 2024/04/01 19:14:33 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct ft_read_s
{
	int bytes_readed;
	char *buf;
} ft_read_t;

ft_read_t	ft_read(int fd)
{
	ft_read_t read_value;

	read_value.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_value.buf)
	{
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	read_value.bytes_readed = read(fd, read_value.buf, BUFFER_SIZE);
	if (read_value.bytes_readed == -1)
	{
		read_value.buf = NULL;
		read_value.bytes_readed = -1;
		return (read_value);
	}
	read_value.buf[read_value.bytes_readed] = '\0';
	return read_value;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ft_read_t	read_value;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_value.bytes_readed = 1;
	while (!ft_strchr(stash, '\n') && read_value.bytes_readed != 0)
	{
		read_value = ft_read(fd);
		if (read_value.bytes_readed == -1)
		{
			free(read_value.buf);
			free(stash);
            stash = NULL;
            return (NULL);
		}
		stash = strjoin_free(stash, read_value.buf);
	}
	free(read_value.buf);
	line = // line
	stash = // stash
	return (line);
}
