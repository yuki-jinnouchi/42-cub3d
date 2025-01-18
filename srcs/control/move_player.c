/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:16:28 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 18:01:42 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_vars *vars, double dir_degree)
{
	t_player	*player;
	double		dir_rad;
	double		screen_dir;

	player = vars->player;
	player->move_num++;
	dir_rad = deg_to_rad(dir_degree);
	while (player->move_num > 0)
	{
		screen_dir = add_rad(player->dir, dir_rad - PI / 2);
		player->pos.x += cos(screen_dir) * MOVE_SPEED;
		player->pos.y += sin(screen_dir) * MOVE_SPEED;
		draw_screen(vars);
		player->move_num = 0;
	}
}
