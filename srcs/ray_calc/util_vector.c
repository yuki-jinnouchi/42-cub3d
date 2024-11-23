/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/23 03:15:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int write_line(int color, int x, t_vars *vars)
{
    int wall_height;
    int y;

    wall_height = vars->window_height / 2;
    y = (vars->window_height / 2) - (wall_height / 2);
    while(y < (vars->window_height / 2) + (wall_height / 2))
    {
        my_mlx_pixel_put(vars->image, x, y, color);
        y++;
    }
    return (SUCCESS);
}

int draw_plane(t_vars *vars)
{
    // t_player *player;
    int x;
    // int y;

    // player = vars->player;
    x = 0;
    while(x < vars->window_width)
    {
        write_line(0x000000FF, x, vars);
        x++;
    }
    return (SUCCESS);
}

int update_plane(t_player *player)
{
    player->plane.x = tan(player->fov_rad / 2) * sin(player->dir + (PI / 2));
    player->plane.y = tan(player->fov_rad / 2) * cos(player->dir + (PI / 2));
    // printf("player->dir_vec.x: %f\n", player->dir_vec.x);
    // printf("player->dir_vec.y: %f\n", player->dir_vec.y);
    // printf("tan(player->fov_rad / 2): %f\n", tan(player->fov_rad / 2));
    // printf("cos(player->dir - (PI / 2)): %f\n", cos(player->dir - (PI / 2)));
    // printf("sin(player->dir - (PI / 2)): %f\n", sin(player->dir - (PI / 2)));
    // printf("plane.x: %f\n", player->plane.x);
    // printf("plane.y: %f\n", player->plane.y);
    return (SUCCESS);
}
