/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:41 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/21 21:03:46 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;

	if (dst == src)
		return (dst);
	if (dst < src)
	{
		dst2 = (char *)dst;
		src2 = (char *)src;
		while (len--)
			*dst2++ = *src2++;
	}
	else
	{
		dst2 = (char *)dst + len;
		src2 = (char *)src + len;
		while (len--)
			*--dst2 = *--src2;
	}
	return (dst);
}
