/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:25:49 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/20 18:10:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	draw_init_background(vars);
	return (SUCCESS);
}

/*
int bg_image_init(t_vars *vars)
{
	t_image	*bg_image;

	vars->bg_image = (t_image *) malloc(sizeof(t_image));
	if (vars->bg_image == NULL)
		return (FAILURE);
	bg_image = vars->bg_image;
	bg_image->img = mlx_new_image(vars->mlx, vars->window_width, \
		vars->window_height);
	bg_image->addr = mlx_get_data_addr(bg_image->img, &bg_image->bits_per_pixel, \
		&bg_image->line_length, &bg_image->endian);
	// draw_background(vars);
	return (SUCCESS);
}
*/
