/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:29:33 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/28 02:43:56 by yjinnouc         ###   ########.fr       */
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
        // printf("back\n");
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
        // printf("back\n");
        next_pos.x = jump_next_pos(pos.x, ray.x);
        if (slope_x != 0)
            next_pos.y = pos.y + (next_pos.x - pos.x) / slope_x;
    }
    return (next_pos);
}

t_vec calc_ray_flat(t_vec *ray, t_player *player, t_vars *vars)
{
    double  slope_y;
    t_vec   last_pos;
    t_vec   current_pos;
    int     wall_direction;

    slope_y = ray->y / ray->x;
    last_pos = player->pos;
    current_pos = player->pos;
    while(TRUE)
    {
        // current_pos = get_next_pos_flat(last_pos, *ray, slope_y);
        // printf("calc_ray_flat last_pos.x: %f, last_pos.y: %f ", last_pos.x, last_pos.y);
        // printf("calc_ray_flat current_pos.x: %f, current_pos.y: %f\n", current_pos.x, current_pos.y);
        wall_direction = check_wall_num( \
            current_pos, *ray, vars->map->structure);
        if (wall_direction != 0) // if ray hits top wall
        {
            // printf("wall_direction: %i\n\n", wall_direction);
            return (current_pos); // flag = TRUE; and save vector and wall name;
        }
        last_pos = current_pos;
        current_pos = get_next_pos_flat(last_pos, *ray, slope_y);
    }
}

t_vec calc_ray_steep(t_vec *ray, t_player *player, t_vars *vars)
{
    double  slope_x;
    t_vec   last_pos;
    t_vec   current_pos;
    int     wall_direction;

    slope_x = ray->x / ray->y;
    last_pos = player->pos;
    current_pos = player->pos;
    while(TRUE)
    {
        // current_pos = get_next_pos_steep(last_pos, *ray, slope_x);
        // printf("calc_ray_steep last_pos.x: %f, last_pos.y: %f\n", last_pos.x, last_pos.y);
        // printf("calc_ray_steep current_pos.x: %f, current_pos.y: %f\n", current_pos.x, current_pos.y);
        wall_direction = check_wall_num( \
            current_pos, *ray, vars->map->structure);
        // printf("calc_ray_steep_x current_pos.x: %f, current_pos.y: %f, wall_direction: %i\n", current_pos.x, current_pos.y, wall_direction);
        if (wall_direction != 0) // if ray hits left wall
        {
            // printf("wall_direction: %i\n\n", wall_direction);
            return (current_pos); // flag = TRUE; and save vector and wall name;
        }
        last_pos = current_pos;
        current_pos = get_next_pos_steep(last_pos, *ray, slope_x);
    }
}

t_vec calc_ray(t_player *player, int window_width, int i)
{
    t_vec   ray;
    double  camera_x;

    camera_x = (2 * i / (double) window_width) - 1;
    // printf("calc_ray camera_x: %f\n", camera_x);
    ray.x = player->dir_vec.x + player->plane.x * camera_x;
    ray.y = player->dir_vec.y + player->plane.y * camera_x;
    // printf("calc_ray ray.x: %f\n", ray.x);
    // printf("calc_ray ray.y: %f\n", ray.y);
    return (ray);
}