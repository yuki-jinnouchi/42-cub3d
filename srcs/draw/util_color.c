/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 07:04:58 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_uint_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_image_color(t_image *image, int x, int y)
{
	int	*color;

	color = (int *)(image->addr + \
		(y * image->line_length) + \
		(x * image->bits_per_pixel / 8));
	return (*color);
}

int	get_image_color_by_ratio(\
	t_image *image, double x_ratio, double y_ratio, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	x = (int)(image->width * x_ratio);
	y = (int)(image->height * y_ratio);
	if (x == vars->last_wall_x && y == vars->last_wall_y)
		return (vars->last_color);
	vars->last_wall_x = x;
	vars->last_wall_y = y;
	color = get_image_color(image, x, y);
	vars->last_color = color;
	return (color);
}

t_image	*get_texture(int direction, t_vars *vars)
{
	if (direction == NORTH)
		return (vars->texture->n);
	else if (direction == EAST)
		return (vars->texture->e);
	else if (direction == SOUTH)
		return (vars->texture->s);
	else if (direction == WEST)
		return (vars->texture->w);
	else
		return (NULL);
}

int	get_texture_color( \
	t_wall *wall, double window_y_ratio, t_vars *vars)
{
	int	color;

	if (wall->direction == NORTH)
		color = get_image_color_by_ratio(vars->texture->n, \
			fmod(wall->pos.x, 1.0), window_y_ratio, vars);
	else if (wall->direction == EAST)
		color = get_image_color_by_ratio(vars->texture->e, \
			fmod(wall->pos.y, 1.0), window_y_ratio, vars);
	else if (wall->direction == SOUTH)
		color = get_image_color_by_ratio(vars->texture->s, \
			1 - fmod(wall->pos.x, 1.0), window_y_ratio, vars);
	else if (wall->direction == WEST)
		color = get_image_color_by_ratio(vars->texture->w, \
			1 - fmod(wall->pos.y, 1.0), window_y_ratio, vars);
	else
		return (FAILURE);
	return (color);
}
