/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:14:30 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 23:19:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_vars *vars, double abs_dir)
{
	t_player	*player;

	player = vars->player;
	player->dir = add_rad(player->dir, abs_dir * ROTATE_SPEED * PI / 180);
	player->dir_vec = dir_to_vec(player->dir);
	update_plane(player);
	draw_screen(vars);
}
