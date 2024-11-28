/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:42:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/28 02:43:31 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_vec calc_wall_pos(t_vec *ray, t_player *player, t_vars *vars)
{
    t_vec    wall_pos;

    // printf("calc_wall_pos ray.x: %f, ray.y: %f\n", ray->x, ray->y);
    if (ABS(ray->x) >= ABS(ray->y))
        wall_pos = calc_ray_flat(ray, player, vars);
    else
        wall_pos = calc_ray_steep(ray, player, vars);
    return (wall_pos);
}
