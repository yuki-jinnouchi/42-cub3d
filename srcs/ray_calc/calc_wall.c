/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:42:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 00:26:42 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
check the ray beam to hit the wall and return the t_wall struct it contains
- wall.pos: the position of the hit wall
- wall.direction: the structure of the hit wall
*/
t_wall	calc_wall_position(t_dvec ray, t_dvec pos, t_vars *vars)
{
	t_wall	wall;
	t_dvec	last_pos;
	t_dvec	current_pos;

	last_pos = pos;
	current_pos = pos;
	while (TRUE)
	{
		wall.direction = check_wall_num(\
			current_pos, ray, vars->map->structure);
		if (wall.direction != 0)
		{
			wall.pos = current_pos;
			return (wall);
		}
		last_pos = current_pos;
		current_pos = next_pos(last_pos, ray);
	}
}

t_wall	calc_wall(t_player *player, int window_x, t_vars *vars)
{
	t_wall	wall;
	t_dvec	ray;

	ray = calc_raycast(player, vars->window_width, window_x);
	// printf("ray.x: %f, ray.y: %f, ", ray.x, ray.y);
	wall = calc_wall_position(ray, player->pos, vars);
	// printf("wall.pos.x: %f, wall.pos.y: %f\n", wall.pos.x, wall.pos.y);
	wall.plane_distance = calc_plane_distance(wall.pos, player);
	wall.ray_distance = calc_ray_distance(wall.pos, player->pos);
	wall.wall_height = (vars->window_height / wall.plane_distance);
	wall.past_wall_height = vars->wall_heights[window_x];
	wall.window_start = (vars->window_height / 2) - (wall.wall_height / 2);
	wall.window_end = (vars->window_height / 2) + (wall.wall_height / 2);
	return (wall);
}
