/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:40:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/19 02:28:18 by yjinnouc         ###   ########.fr       */
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

//時計回りに北から360度 0, 90, 180, 270
int	player_init(t_vars *vars)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	if (player == NULL)
		return (FAILURE);
	vars->player = player;
	player->pos.x = vars->input->position.x;
	player->pos.y = vars->input->position.y;
	player->dir = deg_to_rad(get_dir(vars));
	player->dir_vec = dir_to_vec(player->dir);
	player->fov_rad = deg_to_rad(FOV);
	update_plane(player);
	player->vel.x = 0;
	player->vel.y = 0;
	player->move_num = 0;
	player->rotate_num = 0;
	return (SUCCESS);
}
