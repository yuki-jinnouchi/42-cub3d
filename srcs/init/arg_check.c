	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/16 17:10:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
		printf("Usage: ./cub3D <map.cub>\n");
		return (FALSE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		printf("Error\n");
		printf("Invalid file extension\n");
		return (FALSE);
	}
	// if (open(argv[1], O_RDONLY) == -1)
	// {
	// 	printf("Error\n");
	// 	printf("Failed to open file\n");
	// 	return (FALSE);
	// }
	return (TRUE);
}
