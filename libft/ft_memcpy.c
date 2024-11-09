/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:38 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/21 21:03:41 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	i = 0;
	if (dst == src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (const char *)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
