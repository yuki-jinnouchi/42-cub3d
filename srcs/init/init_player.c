/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:40:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/28 23:19:18by rhakobori        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dir(t_vars *vars)
{
	if (vars->input->dir == 'N')
		return (0);
	if (vars->input->dir == 'E')
		return (90);
	if (vars->input->dir == 'S')
		return (180);
	if (vars->input->dir == 'W')
		return (270);
	return (FAILURE);
}

void	player_init(t_vars *vars)
{
	t_player	*player;

	player = &vars->player;
	player->pos.x = vars->input->position.x;
	player->pos.y = vars->input->position.y;
	player->dir = get_dir(vars); //時計回りに北から360度 0, 90, 180, 270
	player->dir_vec = dir_to_vec(player->dir);
	player->fov_rad = deg_to_rad(FOV);
	update_plane(player);
	player->vel.x = 0;
	player->vel.y = 0;
	player->move_num = 0;
}
