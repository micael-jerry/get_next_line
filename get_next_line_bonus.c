/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:12:22 by mfidimal          #+#    #+#             */
/*   Updated: 2024/04/13 11:25:00 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *global_tmp)
{
	char	*line;
	int		i;

	if (!global_tmp || !global_tmp[0])
		return (NULL);
	i = 0;
	while (global_tmp[i] && global_tmp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (global_tmp[i])
	{
		line[i] = global_tmp[i];
		i++;
		if (global_tmp[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_global_tmp(char *global_tmp)
{
	char	*new_global_tmp;
	int		i;
	int		j;

	i = 0;
	while (global_tmp[i] && global_tmp[i] != '\n')
		i++;
	if (global_tmp[i] == '\0')
		return (free(global_tmp), NULL);
	new_global_tmp = (char *)malloc(sizeof(char) * (ft_strlen(global_tmp) - i
				+ 1));
	if (!new_global_tmp)
		return (NULL);
	i++;
	j = 0;
	while (global_tmp[i])
	{
		new_global_tmp[j] = global_tmp[i];
		i++;
		j++;
	}
	new_global_tmp[j] = '\0';
	return (free(global_tmp), new_global_tmp);
}

char	*get_next_line(int fd)
{
	static char	*global_tmp[LIMIT_FD_MAX];
	char		*buffer;
	char		*line;
	int			bytes_readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(buffer), NULL);
		buffer[bytes_readed] = '\0';
		global_tmp[fd] = strjoin_free(global_tmp[fd], buffer);
		if (ft_strchr(global_tmp[fd], '\n'))
			break ;
	}
	line = get_line(global_tmp[fd]);
	global_tmp[fd] = get_global_tmp(global_tmp[fd]);
	return (free(buffer), line);
}
