/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:31 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/04 14:36:30 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (*s2 == c2)
			return ((void *)s2);
		s2++;
	}
	return (NULL);
}
