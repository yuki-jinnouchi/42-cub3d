/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:41 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 02:47:46 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int window_init(t_vars *vars)
{
	vars->window_width = WINDOW_WIDTH * BASE_SIZE;
	vars->window_height = WINDOW_HEIGHT * BASE_SIZE;
	vars->window = mlx_new_window(vars->mlx, vars->window_width, \
		vars->window_height, WINDOW_TITLE);
	return (SUCCESS);
}

int image_init(t_vars *vars)
{
	t_image *image;

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

t_vars *vars_init(char **argv)
{
	t_vars	*vars;

	vars = (t_vars *) malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
    vars->filename = ft_strdup(argv[1]);
    vars->mlx = mlx_init();
	if (window_init(vars) == FAILURE)
		return (NULL);
	if (image_init(vars) == FAILURE)
		return (NULL);
    vars->map = (t_map *) map_init(vars);
	if (vars->map == NULL)
		return (NULL);
	if (texture_init(vars) == FAILURE)
		return (NULL);
	if (player_init(vars) == FAILURE)
		return (NULL);
    return (vars);
}
