/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:41:07 by hakobori          #+#    #+#             */
/*   Updated: 2024/08/01 15:51:59 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		count;
	size_t	i;
	size_t	start;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			count++;
	}
	return (count);
}

static char	*ft_strndup(char const *s, size_t n)
{
	size_t	i;
	char	*result;

	result = (char *)ft_calloc(n + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

static void	ft_free_2d_array(char **head)
{
	int	i;

	i = 0;
	while (head[i])
		free(head[i++]);
	free(head);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char		**head;
	const char	*start;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	head = result;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			*result++ = ft_strndup(start, s - start);
			if (!*(result - 1))
				return (ft_free_2d_array(head), NULL);
		}
	}
	return (head);
}
