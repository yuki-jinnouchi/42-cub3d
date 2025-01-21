/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:24:08 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/19 02:24:16 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_vars *vars, double rotate_dir)
{
	t_player	*player;

	player = vars->player;
	player->dir = add_rad(player->dir, rotate_dir * ROTATE_SPEED * PI / 180);
	player->dir_vec = dir_to_vec(player->dir);
	update_plane(player);
}
