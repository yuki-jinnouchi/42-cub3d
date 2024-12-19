/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:43:55 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 16:52:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->window_width)
	{
		y = 0;
		while (y < vars->window_height / 2)
		{
			my_mlx_pixel_put(vars->image, x, y, vars->texture->ceil_argb);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < vars->window_width)
	{
		y = vars->window_height / 2;
		while (y < vars->window_height)
		{
			my_mlx_pixel_put(vars->image, x, y, vars->texture->floor_argb);
			y++;
		}
		x++;
	}
}
