/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/21 18:52:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// In these functions, v represents either x or y coordinate

int	update_plane(t_player *player)
{
	player->plane.x = tan(player->fov_rad / 2) * cos(player->dir);
	player->plane.y = tan(player->fov_rad / 2) * sin(player->dir);
	return (SUCCESS);
}

// Check if vector change (current and last) makes cross line or not.
// Note that v_last and v_current can be on the grid.
int	is_cross_line(double v_current, double v_last)
{
	int	curr_on_grid;
	int	last_on_grid;
	int	not_same_floor;

	curr_on_grid = (fmod(v_current, 1.0) == 0);
	last_on_grid = (fmod(v_last, 1.0) == 0);
	not_same_floor = (floor(v_last) != floor(v_current));
	if (curr_on_grid && last_on_grid && not_same_floor)
		return (TRUE);
	else if (curr_on_grid && !last_on_grid)
		return (TRUE);
	else if (!curr_on_grid && !last_on_grid && not_same_floor)
		return (TRUE);
	else
		return (FALSE);
}

// Calculate next v (x/y) grid position.
double	next_grid_v(double v_pos, double v_ray)
{
	if (fmod(v_pos, 1.0) == 0.0)
	{
		if (v_ray > 0)
			return (v_pos + 1.0);
		else
			return (v_pos - 1.0);
	}
	else
	{
		if (v_ray > 0)
			return (ceil(v_pos));
		else
			return (floor(v_pos));
	}
}

// Check wall number (to get texture) from position and ray information.
int	check_wall_num(t_dvec pos, t_dvec ray, char **structure)
{
	if (ray.y < 0 && fmod(pos.y, 1.0) == 0.0 && \
		structure[(int) pos.y - 1][(int) pos.x] == '1')
		return (NORTH);
	if (ray.y >= 0 && fmod(pos.y, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x] == '1')
		return (SOUTH);
	if (ray.x < 0 && fmod(pos.x, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x - 1] == '1')
		return (WEST);
	if (ray.x >= 0 && fmod(pos.x, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x] == '1')
		return (EAST);
	return (FALSE);
}
