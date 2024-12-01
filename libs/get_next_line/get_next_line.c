/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:42 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/01 13:45:57 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		result = ft_strjoin(result, str);
		if (!result)
			return (free(first), NULL);
		free(first);
		if (c == '\n')
			break ;
	}
	return (result);
}

// #include <fcntl.h>
// #include <libc.h>
// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("text.txt",O_RDONLY);
// 	line = NULL;
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			return (0);
// 		printf("[%i] = %s", i+1, line);
// 		printf("len = %zu\n", strlen(line));
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }
