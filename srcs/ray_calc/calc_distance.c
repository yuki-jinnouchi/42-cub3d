/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:40:17 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/21 18:20:03 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
