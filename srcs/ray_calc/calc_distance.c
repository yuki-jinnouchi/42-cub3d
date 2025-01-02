/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:40:17 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 05:44:28 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_dir_wall_distance(t_dvec pos, int dir, t_vars *vars)
{
	t_dvec	ray;
	double	distance;
	t_wall	wall;

	ray.x = 0;
	ray.y = 0;
	if (dir == NORTH)
		ray.y = -1;
	else if (dir == EAST)
		ray.x = 1;
	else if (dir == SOUTH)
		ray.y = 1;
	else if (dir == WEST)
		ray.x = -1;
	wall = calc_wall_position(ray, pos, vars);
	distance = calc_ray_distance(wall.pos, pos);
	return (distance);
}

// calculate distance between player and whole wall
double	calc_wall_distance(t_dvec pos, t_vars *vars)
{
	double	distance[4];
	double	min_distance;

	distance[NORTH - 1] = calc_dir_wall_distance(pos, NORTH, vars);
	distance[EAST - 1] = calc_dir_wall_distance(pos, EAST, vars);
	distance[SOUTH - 1] = calc_dir_wall_distance(pos, SOUTH, vars);
	distance[WEST - 1] = calc_dir_wall_distance(pos, WEST, vars);
	min_distance = distance[NORTH - 1];
	min_distance = fmin(min_distance, distance[EAST - 1]);
	min_distance = fmin(min_distance, distance[SOUTH - 1]);
	min_distance = fmin(min_distance, distance[WEST - 1]);
	return (min_distance);
}

// calculate distance between player and touched point of wall
double	calc_ray_distance(t_dvec wall_pos, t_dvec player_pos)
{
	double	distance;

	distance = sqrt(pow(wall_pos.x - player_pos.x, 2) + \
		pow(wall_pos.y - player_pos.y, 2));
	return (distance);
}

// calculate distance between touched point of wall and the plane
double	calc_plane_distance(t_dvec wall_pos, t_player *player)
{
	double	distance;

	distance = calc_ray_distance(wall_pos, player->pos) * \
		cos(atan2(wall_pos.y - player->pos.y, wall_pos.x - player->pos.x) - \
		atan2(player->dir_vec.y, player->dir_vec.x));
	return (distance);
}
