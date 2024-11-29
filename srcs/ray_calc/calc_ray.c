/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:29:33 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 10:58:23 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec get_next_pos_flat(t_vec pos, t_vec ray, double slope_y)
{
    t_vec    next_pos;

    next_pos.x = jump_next_pos(pos.x, ray.x);
    next_pos.y = pos.y + slope_y * (next_pos.x - pos.x);
    if (check_cross_line(next_pos.y, pos.y) == TRUE)
    {
        next_pos.y = jump_next_pos(pos.y, ray.y);
        if (slope_y != 0)
            next_pos.x = pos.x + (next_pos.y - pos.y) / slope_y;
    }
    return (next_pos);
}

t_vec get_next_pos_steep(t_vec pos, t_vec ray, double slope_x)
{
    t_vec    next_pos;

    next_pos.y = jump_next_pos(pos.y, ray.y);
    next_pos.x = pos.x + slope_x * (next_pos.y - pos.y);
    if (check_cross_line(next_pos.x, pos.x) == TRUE)
    {
        next_pos.x = jump_next_pos(pos.x, ray.x);
        if (slope_x != 0)
            next_pos.y = pos.y + (next_pos.x - pos.x) / slope_x;
    }
    return (next_pos);
}

t_vec calc_ray(t_player *player, int window_width, int i)
{
    t_vec   ray;
    double  camera_x;

    camera_x = (2 * i / (double) window_width) - 1;
    ray.x = player->dir_vec.x + player->plane.x * camera_x;
    ray.y = player->dir_vec.y + player->plane.y * camera_x;
    return (ray);
}
