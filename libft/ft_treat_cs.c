/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:58:59 by hakobori          #+#    #+#             */
/*   Updated: 2024/07/31 14:40:04 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_treat_char(int c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_treat_string(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}
