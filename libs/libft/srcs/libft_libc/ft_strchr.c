/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:49:56 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/27 14:46:51 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	tmp_c;

	tmp_c = (unsigned char) c;
	while (*s != '\0' && *s != tmp_c)
		s++;
	if (*s == tmp_c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>

int main (void)
{
	const char *s = "MMMOOONNNKKKEEEYYY";
	printf("ans:%s\n", ft_strchr(s, 'N'));
	return (0);
}
*/