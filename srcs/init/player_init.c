/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:40:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 04:19:04 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int player_init(t_vars *vars)
{
	t_player *player;

	player = (t_player *) malloc(sizeof(t_player));
	if (player == NULL)
		return (FAILURE);
	vars->player = player;
	player->pos.x = 4.5;
	player->pos.y = 4.5;
	player->dir = 0;
	player->vel.x = 0;
	player->vel.y = 0;
	player->move_num = 0;
	return (SUCCESS);
}
