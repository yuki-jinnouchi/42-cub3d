/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:43:06 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/20 22:20:54 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arg_check(int argc, char **argv)
{
	int	arg_len;

	arg_len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (FALSE);
	}
	if (arg_len < 5)
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (FALSE);
	}
	if (ft_strncmp(argv[1] + arg_len - 4, ".cub", 4) != 0)
	{
		pft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (FALSE);
	}
	return (TRUE);
}
