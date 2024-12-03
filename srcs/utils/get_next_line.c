/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:42 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 21:37:23 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}

static int	ft_getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (READ_ERROR);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	else
		return (EOF);
}

char	*get_next_line(int fd)
{
	char	*first;
	char	*result;
	char	str[2];
	char	c;

	result = NULL;
	str[0] = '\0';
	str[1] = '\0';
	while (fd >= 0)
	{
		first = result;
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		if (c == READ_ERROR)
			return (free(result), NULL);
		str[0] = c;
		result = ft_strjoin_gnl(first, str);
		if (!result)
			return (free(first), NULL);
		free(first);
		if (c == '\n')
			break ;
	}
	return (result);
}
