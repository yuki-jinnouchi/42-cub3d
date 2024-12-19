/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:41 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 01:53:41 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_init(t_vars *vars)
{
	vars->window_width = WINDOW_WIDTH;
	vars->window_height = WINDOW_HEIGHT;
	vars->window = mlx_new_window(vars->mlx, vars->window_width, \
		vars->window_height, WINDOW_TITLE);
	return (SUCCESS);
}

int	image_init(t_vars *vars)
{
	t_image	*image;

	vars->image = (t_image *) malloc(sizeof(t_image));
	if (vars->image == NULL)
		return (FAILURE);
	image = vars->image;
	image->img = mlx_new_image(vars->mlx, vars->window_width, \
		vars->window_height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
	return (SUCCESS);
}

int	set_vars(t_vars	*vars, t_input *map_info)
{
	vars->texture->n.addr = map_info->no;
	vars->texture->s.addr = map_info->so;
	vars->texture->e.addr = map_info->ea;
	vars->texture->w.addr = map_info->we;
	vars->map->height = map_info->height;
	vars->map->width = map_info->width;
	vars->map->structure = map_info->structure;
	return (SUCCESS);
}

int	vars_init(char **argv, t_input	*map_info, t_vars *vars)
{
	vars->filename = ft_strdup(argv[1]);
	vars->input = map_info;
	vars->mlx = mlx_init();
	if (window_init(vars) == FAILURE)
		return (FAILURE);
	if (image_init(vars) == FAILURE)
		return (FAILURE);
	vars->map = (t_map *) map_init(vars);
	if (vars->map == NULL)
		return (FAILURE);
	if (texture_init(vars) == FAILURE)
		return (FAILURE);
	player_init(vars);
	free_map_info_after_init(map_info);
	return (SUCCESS);
}
