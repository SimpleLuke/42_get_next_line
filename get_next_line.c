/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:52 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 13:00:43 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_next_line(int fd);
static int	copy_rest(char buf[], char *line);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_count;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')))
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count < 1)
			break ;
		buf[read_count] = '\0';
		line = ft_strjoin(line, buf, read_count);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	to_copy = copy_rest(buf, line);
	line[to_copy] = '\0';
	return (line);
}

static int	copy_rest(char buf[], char *line)
{
	char	*newline;
	int		to_copy;

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	return (to_copy);
}
