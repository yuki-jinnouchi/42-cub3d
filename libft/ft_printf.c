/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:39:54 by hakobori          #+#    #+#             */
/*   Updated: 2024/07/31 14:40:20 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_treat_smt(char *str, va_list args, int fd)
{
	int	ret;

	ret = 0;
	str++;
	if (!(*str))
		ret = 0;
	else if (*str == 'c')
		ret = ft_treat_char(va_arg(args, int), fd);
	else if (*str == 's')
		ret = ft_treat_string(va_arg(args, char *), fd);
	else if (*str == 'p')
		ret = ft_treat_p(va_arg(args, void *), fd);
	else if (*str == 'd' || *str == 'i')
		ret = ft_trest_di(va_arg(args, int), fd);
	else if (*str == 'u')
		ret = ft_treat_u(va_arg(args, unsigned int), fd);
	else if (*str == 'x' || *str == 'X')
		ret = ft_treat_hex(va_arg(args, unsigned int), *str, fd);
	else if (*str == '%')
		ret = ft_treat_char('%', fd);
	else
		ret = ft_treat_char(*str, fd);
	return (ret);
}

int	ft_printf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		ret;
	char	*str;

	str = (char *)fmt;
	if (!*str)
		return (0);
	ret = 0;
	va_start(ap, fmt);
	while (*str)
	{
		if (*str == '%')
			ret += ft_treat_smt(str++, ap, fd);
		else
		{
			ft_putchar_fd(*str, fd);
			ret++;
		}
		if (*str)
			str++;
	}
	va_end(ap);
	return (ret);
}
