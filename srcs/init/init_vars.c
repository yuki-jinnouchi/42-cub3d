/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:41 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 07:08:46 by yjinnouc         ###   ########.fr       */
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

int	set_vars(t_vars	*vars, t_input *map_info)
{
	vars->texture->n->addr = map_info->no;
	vars->texture->s->addr = map_info->so;
	vars->texture->e->addr = map_info->ea;
	vars->texture->w->addr = map_info->we;
	vars->map->height = map_info->height;
	vars->map->width = map_info->width;
	vars->map->structure = map_info->structure;
	return (SUCCESS);
}

t_vars	*vars_init(char **argv, t_input	*map_info)
{
	t_vars	*vars;

	vars = (t_vars *) malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	vars->filename = ft_strdup(argv[1]);
	vars->input = map_info;
	vars->mlx = mlx_init();
	if (window_init(vars) == FAILURE)
		return (NULL);
	vars->map = (t_map *) map_init(vars);
	if (vars->map == NULL)
		return (NULL);
	if (texture_init(vars) == FAILURE)
		return (NULL);
	if (player_init(vars) == FAILURE)
		return (NULL);
	if (image_init(vars) == FAILURE)
		return (NULL);
	vars->wall_heights = (int *) \
		malloc(sizeof(int) * vars->window_width);
	gettimeofday(&vars->last_refresh, NULL);
	vars->refresh_rate = 0;
	free_map_info_after_init(map_info);
	return (vars);
}
