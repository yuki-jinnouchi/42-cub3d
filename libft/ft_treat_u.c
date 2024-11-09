/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:55:51 by hakobori          #+#    #+#             */
/*   Updated: 2024/07/31 14:37:45 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_treat_u(unsigned int num, int fd)
{
	int				ret;
	unsigned long	num2;

	num2 = (unsigned long)num;
	ret = 0;
	ft_putnbr_base_fd(num2, fd, &ret, DEC_LOWER_BASE);
	return (ret);
}
