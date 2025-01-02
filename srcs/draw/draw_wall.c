/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:51:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 10:21:13 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_wall_pixel(t_ivec *window_t, t_wall *wall, t_vars *vars)
{
	int			color;

	color = get_texture_color(wall, \
		(double)(window_t->y - wall->window_start) / wall->wall_height, vars);
	if (color != FAILURE)
		my_mlx_pixel_put(vars->image, window_t->x, window_t->y, color);
}

void	draw_wall(t_wall *wall, int window_x, t_vars *vars)
{
	t_ivec	window_t;

	window_t.x = window_x;
	window_t.y = fmax(0, wall->window_start);
	while (window_t.y <= fmin(vars->window_height, wall->window_end))
	{
		put_wall_pixel(&window_t, wall, vars);
		window_t.y++;
	}
}

void	draw_refresh_img(t_vars *vars)
{
	int		window_x;
	t_wall	wall;

	window_x = 0;
	while (window_x < vars->window_width)
	{
		wall = calc_wall(vars->player, window_x, vars);
		draw_ceil(window_x, wall.wall_height, wall.past_wall_height, vars);
		draw_wall(&wall, window_x, vars);
		draw_floor(window_x, wall.wall_height, wall.past_wall_height, vars);
		vars->wall_heights[window_x] = wall.wall_height;
		window_x++;
	}
}
