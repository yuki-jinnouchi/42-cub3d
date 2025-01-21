/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_next_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:12:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/21 18:48:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Calculate the next grid position in the direction of the ray.
	Separate functions handle flat and steep rays to avoid division by zero.
	Each function checks if the next grid position is a wall (or not).
*/
t_dvec	next_pos_flat(t_dvec pos, t_dvec ray)
{
	double	slope_y;
	t_dvec	next_pos;

	slope_y = ray.y / ray.x;
	next_pos.x = next_grid_v(pos.x, ray.x);
	next_pos.y = pos.y + slope_y * (next_pos.x - pos.x);
	if (is_cross_line(next_pos.y, pos.y) == TRUE)
	{
		next_pos.y = next_grid_v(pos.y, ray.y);
		if (slope_y != 0)
			next_pos.x = pos.x + (next_pos.y - pos.y) / slope_y;
	}
	return (next_pos);
}

t_dvec	next_pos_steep(t_dvec pos, t_dvec ray)
{
	double	slope_x;
	t_dvec	next_pos;

	slope_x = ray.x / ray.y;
	next_pos.y = next_grid_v(pos.y, ray.y);
	next_pos.x = pos.x + slope_x * (next_pos.y - pos.y);
	if (is_cross_line(next_pos.x, pos.x) == TRUE)
	{
		next_pos.x = next_grid_v(pos.x, ray.x);
		if (slope_x != 0)
			next_pos.y = pos.y + (next_pos.x - pos.x) / slope_x;
	}
	return (next_pos);
}

t_dvec	next_pos(t_dvec pos, t_dvec ray)
{
	if (abs_double(ray.y) > abs_double(ray.x))
		return (next_pos_steep(pos, ray));
	else
		return (next_pos_flat(pos, ray));
}
