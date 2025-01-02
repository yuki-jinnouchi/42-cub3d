/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:43:55 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 05:40:41 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil(int window_x, int new_height, int past_height, t_vars *vars)
{
	int	ceil_color;
	int	curr_start;
	int	past_start;
	int	window_y;

	ceil_color = vars->texture->ceil_argb;
	past_start = fmax(0, (vars->window_height / 2) - (past_height / 2));
	curr_start = fmax(0, (vars->window_height / 2) - (new_height / 2));
	window_y = fmin(curr_start, past_start);
	while (window_y < curr_start)
	{
		my_mlx_pixel_put(vars->image, window_x, window_y, ceil_color);
		window_y++;
	}
}

void	draw_floor(int window_x, int new_height, int past_height, t_vars *vars)
{
	int	floor_color;
	int	curr_end;
	int	past_end;
	int	window_y;

	floor_color = vars->texture->floor_argb;
	past_end = fmin(vars->window_height, \
		(vars->window_height / 2) + (past_height / 2) + 1);
	curr_end = fmin(vars->window_height, \
		(vars->window_height / 2) + (new_height / 2) + 1);
	window_y = fmin(curr_end, past_end);
	while (window_y < past_end)
	{
		my_mlx_pixel_put(vars->image, window_x, window_y, floor_color);
		window_y++;
	}
}

void	draw_init_background(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < vars->window_width)
	{
		draw_ceil(x, 0, vars->window_height, vars);
		draw_floor(x, 0, vars->window_height, vars);
		x++;
	}
}
