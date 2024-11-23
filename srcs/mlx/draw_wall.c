/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:51:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/23 09:02:51 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    draw_wall(t_vars *vars)
// {
//     int x;
//     int y;
//     int i;
//     int j;

//     x = vars->player->pos.x;
//     y = vars->player->pos.y;
//     i = 0;
//     while (i < 30)
//     {
//         j = 0;
//         while (j < 30)
//         {
//             my_mlx_pixel_put(vars->image, x + i, y + j, 0x00000000);
//             j++;
//         }
//         i++;
//     }
//     // return (SUCCESS);
// }

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
        // printf("here1?\n");
        distance = calc_player_distance(wall_pos, vars->player->pos);
        // printf("here2?\n");
        length = (vars->window_height / distance)/1.5;
        // printf("here3?\n");
        color = 0x00000000;
        if (fmod(wall_pos.x, 1.0) == 0.0)
            color = vars->texture->ceil_argb + 100;
        else if (fmod(wall_pos.y, 1.0) == 0.0)
            color = vars->texture->floor_argb + 100;
        draw_wall_line(length, x_window, color, vars);
        // printf("x_window: %d\n", x_window);
        x_window++;
    }
}
