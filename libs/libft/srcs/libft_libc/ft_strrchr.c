/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:51:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/24 16:03:50 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	tmp_c;
	unsigned int	length;

	tmp_c = (unsigned char) c;
	length = ft_strlen(s);
	s += length;
	while (length > 0 && *s != tmp_c)
	{
		s--;
		length--;
	}
	if (*s == tmp_c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>

// int main (void)
// {
// 	const char *s = "MMMOOONNNKKKEEEYYY";
// 	printf("ans:%s\n", ft_strrchr(s, 'M'));
// 	return (0);
// }
