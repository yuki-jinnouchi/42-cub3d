/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:43:06 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/17 21:03:50 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	arg_check(int argc, char **argv)
{
	int	arg_len;

	arg_len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (FALSE);
	}
	if (arg_len < 5)
	{
		printf("Error\nInvalid file extension\n");
		return (FALSE);
	}
	if (ft_strncmp(argv[1] + arg_len - 4, ".cub", 4) != 0)
	{
		printf("Error\nInvalid file extension\n");
		return (FALSE);
	}
	return (TRUE);
}
