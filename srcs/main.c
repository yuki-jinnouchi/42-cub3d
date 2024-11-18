/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/17 20:33:24 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(char argc, char **argv)
{
	t_map	map_info;
	t_map	*map_info_ptr;

	map_info_ptr = &map_info;
	ft_bzero(map_info_ptr, sizeof(t_map));
	if (map_check(argc, argv, map_info_ptr) == FALSE)
		return (0);
}
