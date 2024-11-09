/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:58:24 by hakobori          #+#    #+#             */
/*   Updated: 2024/07/12 11:57:23 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t	count;
	long	n2;

	count = 0;
	n2 = (long)n;
	if (n2 < 0)
	{
		n2 *= -1;
		count++;
	}
	while (n2 >= 10)
	{
		n2 /= 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	long	n2;
	char	*result;

	n2 = (long)n;
	len = count_len(n);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (n2 < 0)
	{
		result[i++] = '-';
		n2 *= -1;
	}
	while (len && n2 >= 10)
	{
		result[--len] = n2 % 10 + '0';
		n2 /= 10;
	}
	result[--len] = n2 % 10 + '0';
	return (result);
}
