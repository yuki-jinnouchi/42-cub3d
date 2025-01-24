/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:16:28 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/24 21:56:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_move(t_dvec *t_pos, double move_dir, int i, t_vars *vars)
{
	t_wall	wall;
	double	new_move_dir;
	t_dvec	move_ray;

	new_move_dir = add_rad(move_dir, i / 180 * PI);
	move_ray = dir_to_vec(new_move_dir);
	wall = calc_wall_position(move_ray, *t_pos, vars);
	wall.ray_distance = calc_ray_distance(wall.pos, *t_pos);
	t_pos->x += move_ray.x * MOVE_DISTANCE;
	t_pos->y += move_ray.y * MOVE_DISTANCE;
	if (wall.ray_distance <= MOVE_DISTANCE + 0.01)
		return (FALSE);
	else
		return (TRUE);
}

t_dvec	get_next_move_pos(t_player player, double move_dir, t_vars *vars)
{
	int		i;
	t_dvec	t_pos;

	i = 0;
	while (i < 45)
	{
		t_pos = player.pos;
		if (check_player_move(&t_pos, move_dir, i, vars))
			return (t_pos);
		t_pos = player.pos;
		if (check_player_move(&t_pos, move_dir, -i, vars))
			return (t_pos);
		i++;
	}
	return (player.pos);
}

void	move_player(t_vars *vars, double dir)
{
	t_player	*player;
	double		rad;
	double		move_dir;

	player = vars->player;
	rad = deg_to_rad(dir);
	move_dir = add_rad(player->dir, rad);
	player->pos = get_next_move_pos(*player, move_dir, vars);
}
