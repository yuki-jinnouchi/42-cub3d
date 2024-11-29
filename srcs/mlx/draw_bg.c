/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:43:55 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 02:28:42 by yjinnouc         ###   ########.fr       */
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
		while (y < vars->window_height)
		{
			if (y < vars->window_height / 2)
				my_mlx_pixel_put(vars->image, x, y, vars->texture->ceil_argb);
			else
				my_mlx_pixel_put(vars->image, x, y, vars->texture->floor_argb);
			y++;
		}
		x++;
	}
}
