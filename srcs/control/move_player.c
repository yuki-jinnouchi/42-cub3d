/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:16:28 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 12:06:38 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_vars *vars, double dir)
{
	t_player	*player;

	player = vars->player;
	player->dir = add_rad(player->dir, dir * ROTATE_SPEED * PI / 180);
	player->dir_vec = dir_to_vec(player->dir);
	update_plane(player);
	draw_screen(vars);
}

void	move_player(t_vars *vars, double dir)
{
	t_player	*player;
	double		screen_dir;

	player = vars->player;
	player->move_num = FRAME_RATE / 10;
	while (player->move_num > 0)
	{
		screen_dir = add_rad(player->dir, dir - PI / 2);
		player->pos.x += cos(screen_dir) * MOVE_SPEED;
		player->pos.y += sin(screen_dir) * MOVE_SPEED;
		draw_screen(vars);
		player->move_num--;
	}
}
