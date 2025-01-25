/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:07:10 by yjinnouc          #+#    #+#             */
/*   Updated: 2023/12/02 18:29:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters n: the integer to convert.
Return value The string representing the integer.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

int	len_int(int n)
{
	unsigned int	count;

	count = 0;
	if (n == INT_MIN)
	{
		n = INT_MAX;
		count ++;
	}
	else if (n < 0)
	{
		n *= -1;
		count ++;
	}
	while (n >= 10)
	{
		n /= 10;
		count ++;
	}
	count++;
	return (count);
}

void	int_to_str(int n, char *ptr, unsigned int length)
{
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 0 && length > 0)
	{
		ptr[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	length;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = len_int(n);
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	int_to_str(n, ptr, length);
	ptr[length] = 0;
	return (ptr);
}
