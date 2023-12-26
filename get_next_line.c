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

/* **************************************************************************
 * Summary of the file:
 *
 * 		This function reads the file descriptor and returns a line.
 * 		A line defines as encounter a newline or EOF.
 * 		A repeated call reads and returns the next line.
 * 		It returns NULL when it encounters error or EOF.
 *
 * **************************************************************************/
#include "get_next_line.h"

char		*get_next_line(int fd);
static int	copy_rest(char buf[], char *line);

/* **************************************************************************
 * char	*get_next_line(int fd)
 *
 * Summary of the function:
 * 
 * 		This function reads the file with the BUFFER_SIZE until it
 * 		encounters a newline or reaches the EOF.
 * 		Line keeps track to the previous stored string and the newly
 * 		joined string.
 * 		Then it copies what after the newline to the static buffer.
 * 		The static buffer stores the string for the next call.
 * 		And null-terminating the line before the newline.
 * 
 * Parameters: A file descriptor.
 *
 * Return value: A pointer to the line.
 * **************************************************************************/
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_count;
	int			line_count;

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
	line_count = copy_rest(buf, line);
	line[line_count] = '\0';
	return (line);
}

/* **************************************************************************
 * static int	copy_rest(char buf[], char *line)
 *
 * Summary of the function:
 * 
 * 		This function copies what after the newline into buf.
 * 		And it calculates how many characters before the newline.
 *
 * Parameters: The static buffer array and a pointer to the line.
 *
 * Return value: A length of the line plus 1 for null-terminator.
 * **************************************************************************/
static int	copy_rest(char buf[], char *line)
{
	char	*newline;
	int		line_count;

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		line_count = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		line_count = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	return (line_count);
}
