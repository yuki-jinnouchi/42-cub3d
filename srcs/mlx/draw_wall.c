/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:51:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 02:02:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_texture_color( \
	t_wall wall, double y_window_ratio, t_vars vars)
{
	uint32_t	color;

	color = 0;
	if (wall.direction == NORTH)
		color = get_image_color_by_ratio(vars.texture->n, \
			fmod(wall.pos.x, 1.0), y_window_ratio);
	else if (wall.direction == EAST)
		color = get_image_color_by_ratio(vars.texture->e, \
			fmod(wall.pos.y, 1.0), y_window_ratio);
	else if (wall.direction == SOUTH)
		color = get_image_color_by_ratio(vars.texture->s, \
			1 - fmod(wall.pos.x, 1.0), y_window_ratio);
	else if (wall.direction == WEST)
		color = get_image_color_by_ratio(vars.texture->w, \
			1 - fmod(wall.pos.y, 1.0), y_window_ratio);
	return (color);
}

void	draw_wall_line3(t_wall wall, int x_window, t_vars *vars)
{
	int				i;
	int				start;
	int				end;
	uint32_t	color;

	start = (vars->window_height / 2) - (wall.length / 2);
	end = (vars->window_height / 2) + (wall.length / 2);
	i = 0;
	while (i < vars->window_height)
	{
		if (start <= i && i <= end)
		{
			color = get_texture_color(wall, \
				(double)(i - start) / wall.length, *vars);
			my_mlx_pixel_put(vars->image, x_window, i, color);
		}
		i++;
	}
}

void	draw_wall_line2(int x_window, t_vars *vars)
{
	vars->ray = calc_ray(&vars->player, vars->window_width, x_window);
	vars->wall = calc_wall_pos(&(vars->ray), &vars->player, vars);
	vars->wall.distance = calc_plane_distance(vars->wall.pos, &vars->player);
	vars->wall.length = (vars->window_height / vars->wall.distance);
	draw_wall_line3(vars->wall, x_window, vars);
}

void	draw_wall(t_vars *vars)
{
	int	x_window;

	x_window = 0;
	while (x_window < vars->window_width)
	{
		draw_wall_line2(x_window, vars);
		x_window++;
	}
}
