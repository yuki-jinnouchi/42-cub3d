/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:12:33 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/30 22:45:32 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	str_to_int64_within_range(const char *str, int is_minus)
{
	unsigned long	res;
	unsigned long	ul_max;
	unsigned long	num;

	res = 0;
	num = 0;
	ul_max = (unsigned long)LONG_MAX;
	while (*str && ft_isdigit(*str))
	{
		num = *str - '0';
		if (!is_minus && res > ul_max / 10)
			return (LONG_MAX);
		else if (!is_minus && res == ul_max / 10 && num > ul_max % 10)
			return (LONG_MAX);
		else if (is_minus && res > ul_max / 10)
			return (LONG_MIN);
		else if (is_minus && res == ul_max / 10 && num > (ul_max + 1) % 10)
			return (LONG_MIN);
		res = res * 10 + *str++ - '0';
	}
	return (res);
}

long	ft_atol(const char *str)
{
	int		is_minus;
	long	res;

	is_minus = 0;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		is_minus = (*str++ == '-');
	res = str_to_int64_within_range(str, is_minus);
	if (is_minus)
		res = -res;
	return (res);
}
