/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:16:28 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 05:08:18 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_player(t_vars *vars, double dir)
{
    t_player *player;

    player = vars->player;
    player->dir = add_rad(player->dir, ROTATE_SPEED * dir);
    // refresh_screen
}

void move_player(t_vars *vars, double dir)
{
    t_player *player;

    player = vars->player;
    player->move_num = FRAME_RATE / MOVE_SPEED;
    player->vel.x = (MOVE_DISTANCE * cos(player->dir)) / player->move_num;
    player->vel.y = (MOVE_DISTANCE * sin(player->dir)) / player->move_num;
    while(player->move_num > 0)
    {
        player->pos.x +=  cos(dir);
        player->pos.y +=  sin(dir);
        draw_background(vars);
        draw_wall(vars);
        mlx_put_image_to_window(vars->mlx, vars->window, vars->image->img, 0, 0);
        player->move_num--;
    }
}
