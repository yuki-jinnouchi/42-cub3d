/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:56:46 by hakobori          #+#    #+#             */
/*   Updated: 2024/07/31 14:39:55 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digits(int num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	count++;
	return (count);
}

int	ft_trest_di(int num, int fd)
{
	ft_putnbr_fd(num, fd);
	return (ft_get_digits(num));
}
