/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/11/24 16:18:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	start;
	unsigned int	count;

	start = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[start] && start < len)
	{
		count = 0;
		while (big[start + count] == little[count] && start + count < len)
		{
			if (little[count + 1] == 0)
				return ((char *)(big + start));
			count++;
		}
		start++;
	}
	return (0);
}
