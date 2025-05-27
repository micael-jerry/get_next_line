/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:24:52 by mfidimal          #+#    #+#             */
/*   Updated: 2025/05/27 21:05:09 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	while (count < 15)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
