/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:02:52 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/27 18:42:04 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if ((dest == 0 && src == 0) || n == 0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	if (temp_dest > temp_src)
	{
		while (n > 0)
		{
			*(temp_dest + n - 1) = *(temp_src + n - 1);
			n--;
		}
	}
	else if (temp_dest < temp_src)
	{
		while (n > 0)
		{
			*temp_dest++ = *temp_src++;
			n--;
		}
	}
	return (dest);
}
