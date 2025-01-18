/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:42:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 18:03:47 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall_num(t_vec pos, t_vec ray, char **structure)
{
	if (ray.y < 0 && fmod(pos.y, 1.0) == 0.0 && \
		structure[(int) pos.y - 1][(int) pos.x] == '1')
		return (NORTH);
	if (ray.y >= 0 && fmod(pos.y, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x] == '1')
		return (SOUTH);
	if (ray.x < 0 && fmod(pos.x, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x - 1] == '1')
		return (WEST);
	if (ray.x >= 0 && fmod(pos.x, 1.0) == 0.0 && \
		structure[(int) pos.y][(int) pos.x] == '1')
		return (EAST);
	return (FALSE);
}

t_wall	calc_wall_flat(t_vec *ray, t_player *player, t_vars *vars)
{
	t_wall	wall;
	double	slope_y;
	t_vec	last_pos;
	t_vec	current_pos;

	slope_y = ray->y / ray->x;
	last_pos = player->pos;
	current_pos = player->pos;
	while (TRUE)
	{
		wall.direction = check_wall_num(\
			current_pos, *ray, vars->map->structure);
		if (wall.direction != 0)
		{
			wall.pos = current_pos;
			return (wall);
		}
		last_pos = current_pos;
		current_pos = get_next_pos_flat(last_pos, *ray, slope_y);
	}
}

t_wall	calc_wall_steep(t_vec *ray, t_player *player, t_vars *vars)
{
	t_wall	wall;
	double	slope_x;
	t_vec	last_pos;
	t_vec	current_pos;

	slope_x = ray->x / ray->y;
	last_pos = player->pos;
	current_pos = player->pos;
	while (TRUE)
	{
		wall.direction = check_wall_num(\
			current_pos, *ray, vars->map->structure);
		if (wall.direction != 0)
		{
			wall.pos = current_pos;
			return (wall);
		}
		last_pos = current_pos;
		current_pos = get_next_pos_steep(last_pos, *ray, slope_x);
	}
}

t_wall	calc_wall_pos(t_vec *ray, t_player *player, t_vars *vars)
{
	t_wall	wall;

	if (abs_double(ray->x) >= abs_double(ray->y))
		wall = calc_wall_flat(ray, player, vars);
	else
		wall = calc_wall_steep(ray, player, vars);
	return (wall);
}
