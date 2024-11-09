/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:35 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/21 20:38:38 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*unc_s1;
	unsigned char	*unc_s2;

	i = 0;
	unc_s1 = (unsigned char *)s1;
	unc_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (unc_s1[i] != unc_s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (unc_s1[i] - unc_s2[i]);
}
