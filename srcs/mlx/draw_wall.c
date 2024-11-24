/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:51:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/24 04:42:22 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_wall_line(double length, int x_window, int color, t_vars *vars)
{
    int i;
    int start;
    int end;

    start = (vars->window_height / 2) - (length / 2);
    end = (vars->window_height / 2) + (length / 2);
    i = 0;
    while (i < vars->window_height)
    {
        if (start <= i && i <= end)
            my_mlx_pixel_put(vars->image, x_window, i, color);
        // else
        //     my_mlx_pixel_put(vars->image, x_window, i, 0x00FF0000);
        i++;
    }
}

void   draw_wall_wrapper(t_vars *vars)
{
    int x_window;
    double distance;
    double length;
    t_vec wall_pos;
    t_vec ray;
    int color;

    x_window = 0;
    while (x_window < vars->window_width)
    {
        ray = calc_ray(vars->player, vars->window_width, x_window);
        wall_pos = calc_wall_pos(&ray, vars->player, vars);
        // distance = calc_player_distance(wall_pos, vars->player->pos);
        distance = calc_plane_distance(wall_pos, vars->player);
        length = (vars->window_height / distance)/1.5;
        color = 0x00000000;
        if (fmod(wall_pos.x, 1.0) == 0.0 && ray.x < 0)
            color = rgb_to_16argb(120, 0, 255);
        else if (fmod(wall_pos.x, 1.0) == 0.0 && ray.x >= 0)
            color = rgb_to_16argb(0, 180, 255);
        else if (fmod(wall_pos.y, 1.0) == 0.0 && ray.y < 0)
            color = rgb_to_16argb(255, 255, 0);
        else if (fmod(wall_pos.y, 1.0) == 0.0 && ray.y >= 0)
            color = rgb_to_16argb(255, 144, 0);
        draw_wall_line(length, x_window, color, vars);
        x_window++;
    }
}
