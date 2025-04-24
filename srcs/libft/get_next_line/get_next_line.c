/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:08:55 by famirant          #+#    #+#             */
/*   Updated: 2022/11/03 08:23:01 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *lline)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(lline, '\n') && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buf);
			free (lline);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		lline = ft_gnl_strjoin(lline, buf);
	}
	free (buf);
	return (lline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lline[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lline[fd] = ft_read_line(fd, lline[fd]);
	if (!lline[fd])
		return (NULL);
	line = ft_get_line(lline[fd]);
	lline[fd] = ft_new_line(lline[fd]);
	return (line);
}
