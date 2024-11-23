/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:29:33 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/23 08:30:49 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec get_next_pos_flat(t_vec pos, t_vec ray, double slope_y)
{
    t_vec    next_pos;

    if (fmod(pos.x, 1.0) != 0.0)
    {
        if (ray.x > 0)
        {
            next_pos.x = ceil(pos.x);
            next_pos.y = pos.y + slope_y * (ceil(pos.x) - pos.x);
        }
        else
        {
            next_pos.x = floor(pos.x);
            next_pos.y = pos.y + slope_y * (floor(pos.x) - pos.x);
        }
    }
    else
    {
        next_pos.x = pos.x + (double) SIGN(ray.x);
        next_pos.y = pos.y + slope_y * (double) SIGN(ray.x);
    }
    return (next_pos);
}

t_vec get_next_pos_steep(t_vec pos, t_vec ray, double slope_x)
{
    t_vec    next_pos;

    if (fmod(pos.y, 1.0) != 0.0)
    {
        if (ray.y > 0)
        {
            next_pos.y = ceil(pos.y);
            next_pos.x = pos.x + (slope_x * (ceil(pos.y) - pos.y));
        }
        else
        {
            next_pos.y = floor(pos.y);
            next_pos.x = pos.x + (slope_x * (floor(pos.y) - pos.y));
        }
    }
    else
    {
        next_pos.y = pos.y + (double) SIGN(ray.y);
        next_pos.x = pos.x + slope_x * (double) SIGN(ray.y);
    }
    return (next_pos);
}

int check_cross_line(double current, double last)
{
    if (fmod(current, 1.0) != 0.0 && fmod(last, 1.0) != 0.0)
    {
        if (floor(last) != floor(current))
            return (TRUE);
        else
            return (FALSE);
    }
    else
    {
        if (fmod(current, 1.0) == 0.0 && current != last )
            return (TRUE);
        else
            return (FALSE);
    }
}

int check_wall_num(t_vec pos, t_vec ray, char **structure)
{
    // printf("check_wall_num ");
    // printf(" ray.x: %f, ray.y: %f", ray.x, ray.y);
    // printf(" pos.x: %f, int pos.x %i", pos.x, (int) pos.x);
    // printf(" pos.y: %f, int pos.y %i", pos.y, (int) pos.y);
    // printf("\n");
    if (ray.y < 0 && fmod(pos.y, 1.0) == 0.0 &&\
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
        current_pos = get_next_pos_flat(last_pos, *ray, slope_y);
        // printf("calc_ray_steep current_pos.x: %f, current_pos.y: %f\n", current_pos.x, current_pos.y);
        // printf("calc_ray_steep last_pos.x: %f, last_pos.y: %f\n", last_pos.x, last_pos.y);
        // printf("check_cross_line(current_pos.x, last_pos.x): %i\n", check_cross_line(current_pos.x, last_pos.x));
        // printf("check_cross_line(current_pos.y, last_pos.y): %i\n", check_cross_line(current_pos.y, last_pos.y));
        if (check_cross_line(current_pos.x, last_pos.x) == TRUE) // if ray cross left line
            {
                wall_direction = check_wall_num( \
                    current_pos, *ray, vars->map->structure);
                if (wall_direction != 0) // if ray hits left wall
                {
                    // printf("calc_ray_flat_x current_pos.x: %f, current_pos.y: %f, wall_direction: %i\n", current_pos.x, current_pos.y, wall_direction);
                    return (current_pos); // flag = TRUE; and save vector and wall name;
                }
            }
        if (check_cross_line(current_pos.y, last_pos.y) == TRUE) //if ray cross top line
            {
                wall_direction = check_wall_num( \
                    current_pos, *ray, vars->map->structure);
                if (wall_direction != 0) // if ray hits top wall
                {
                    // printf("calc_ray_flat_y current_pos.x: %f, current_pos.y: %f, wall_direction: %i\n", current_pos.x, current_pos.y, wall_direction);
                    return (current_pos); // flag = TRUE; and save vector and wall name;
                }
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
        current_pos = get_next_pos_steep(last_pos, *ray, slope_x);
        // printf("calc_ray_steep current_pos.x: %f, current_pos.y: %f\n", current_pos.x, current_pos.y);
        // printf("calc_ray_steep last_pos.x: %f, last_pos.y: %f\n", last_pos.x, last_pos.y);
        // printf("check_cross_line(current_pos.x, last_pos.x): %i\n", check_cross_line(current_pos.x, last_pos.x));
        // printf("check_cross_line(current_pos.y, last_pos.y): %i\n", check_cross_line(current_pos.y, last_pos.y));
        if (check_cross_line(current_pos.x, last_pos.x) == TRUE) //if ray cross left line
            {
                wall_direction = check_wall_num( \
                    current_pos, *ray, vars->map->structure);
                // printf("calc_ray_steep_x current_pos.x: %f, current_pos.y: %f, wall_direction: %i\n", current_pos.x, current_pos.y, wall_direction);
                if (wall_direction != 0) // if ray hits left wall
                {
                    return (current_pos); // flag = TRUE; and save vector and wall name;
                }
            }
        if (check_cross_line(current_pos.y, last_pos.y) == TRUE) // if ray cross top line
            {
                wall_direction = check_wall_num( \
                    current_pos, *ray, vars->map->structure);
                // printf("calc_ray_steep_y current_pos.x: %f, current_pos.y: %f, wall_direction: %i\n", current_pos.x, current_pos.y, wall_direction);
                if (wall_direction != 0) // if ray hits top wall
                {
                    return (current_pos); // flag = TRUE; and save vector and wall name;
                }
            }
        last_pos = current_pos;
    }
}

double  calc_player_distance(t_vec wall_pos, t_vec player_pos)
{
    double  distance;

    distance = sqrt(pow(wall_pos.x - player_pos.x, 2) + \
        pow(wall_pos.y - player_pos.y, 2));
    return (distance);
}

t_vec calc_wall_pos(t_vec *ray, t_player *player, t_vars *vars)
{
    t_vec    wall_pos;

    if (ABS(ray->x) >= ABS(ray->y))
        wall_pos = calc_ray_flat(ray, player, vars);
    else
        wall_pos = calc_ray_steep(ray, player, vars);
    return (wall_pos);
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
