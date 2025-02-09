/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:29:33 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/21 18:47:33 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate each raycast vector from left to right of the screen
t_dvec	calc_raycast(t_player *player, int window_width, int i)
{
	t_dvec	ray;
	double	camera_x;

	camera_x = (2 * i / (double) window_width) - 1;
	ray.x = player->dir_vec.x + player->plane.x * camera_x;
	ray.y = player->dir_vec.y + player->plane.y * camera_x;
	return (ray);
}
