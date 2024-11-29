/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 10:18:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_plane(t_player *player)
{
	player->plane.x = tan(player->fov_rad / 2) * cos(player->dir);
	player->plane.y = tan(player->fov_rad / 2) * sin(player->dir);
	return (SUCCESS);
}

int	check_cross_line(double current, double last)
{
	if (fmod(current, 1.0) == 0.0)
	{
		if (fmod(last, 1.0) == 0.0)
		{
			if (floor(last) != floor(current))
				return (TRUE);
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
	else
	{
		if (fmod(last, 1.0) != 0.0 && floor(last) != floor(current)) // ayashii
			return (TRUE);
		else
			return (FALSE);
	}
}

double	jump_next_pos(double pos, double ray)
{
	if (fmod(pos, 1.0) == 0.0)
	{
		if (ray > 0)
			return (pos + 1.0);
		else
			return (pos - 1.0);
	}
	else
	{
		if (ray > 0)
			return (ceil(pos));
		else
			return (floor(pos));
	}
}
