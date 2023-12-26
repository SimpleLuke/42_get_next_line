/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:52 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 13:00:43 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_size;
	int		i;

	src_size = ft_strlen(src);
	i = 0;
	if (dest_size > 0)
	{
		while (i < src_size && i < dest_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}

char	*ft_strjoin(char *s1, const char *s2, size_t len)
{
	int		s1_size;
	int		s2_size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = len;
	str = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_size + 1);
	ft_strlcpy((str + s1_size), s2, s2_size + 1);
	free(s1);
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		str_size;

	str_size = ft_strlen(str);
	copy = malloc(sizeof(char) * (str_size + 1));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, str, str_size + 1);
	return (copy);
}
