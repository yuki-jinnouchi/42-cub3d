/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/24 04:14:13 by yjinnouc         ###   ########.fr       */
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
    player->plane.x = tan(player->fov_rad / 2) * cos(player->dir);
    player->plane.y = tan(player->fov_rad / 2) * sin(player->dir);
    return (SUCCESS);
}

int check_cross_line(double current, double last)
{
    if (fmod(current, 1.0) == 0.0)
    {
        if (fmod(last, 1.0) == 0.0)
        {
            if (floor(last) != floor(current))
                return (TRUE);
            else
                return (FALSE);
        }
        else
            return (TRUE);
    }
    else
    {
        if (fmod(last, 1.0) != 0.0 && floor(last) != floor(current)) // ayashii
            return (TRUE);
        else
            return (FALSE);
    }
}

double jump_next_pos(double pos, double ray)
{
    if (fmod(pos, 1.0) == 0.0)
    {
        if (ray > 0)
            return (pos + 1.0);
        else
            return (pos - 1.0);
    }
    else
    {
        if (ray > 0)
            return (ceil(pos));
        else
            return (floor(pos));
    }
}
