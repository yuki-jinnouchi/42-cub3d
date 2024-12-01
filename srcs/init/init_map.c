/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:45:42 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/01 21:14:25 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_init(t_vars *vars)
{
	t_map	*map;
	t_input	*input;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	vars->map = map;
	input = vars->input;
	map->structure = input->structure;
	map->width = input->width;
	map->height = input->height;
	return (map);
}
