/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/22 21:00:36 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	right_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (cmap->x < cmap->len - 1)
	{
		if (ft_isspace(map_info->structure[cmap->y][cmap->x + 1]))
			return (TRUE);
	}
	return (FALSE);
}

int	left_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (cmap->x > 0)
	{
		if (ft_isspace(map_info->structure[cmap->y][cmap->x - 1]))
			return (TRUE);
	}
	return (FALSE);
}

int	up_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (cmap->y <= 0)
		return (FALSE);
	if (cmap->x >= cmap->up_len)
		return (TRUE);
	if (cmap->x < cmap->up_len)
	{
		if (ft_isspace(map_info->structure[cmap->y - 1][cmap->x]))
			return (TRUE);
	}
	return (FALSE);
}

int	down_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (cmap->y >= map_info->height - 1)
		return (FALSE);
	if (cmap->x >= cmap->down_len)
		return (TRUE);
	if (cmap->x < cmap->down_len)
	{
		if (ft_isspace(map_info->structure[cmap->y + 1][cmap->x]))
			return (TRUE);
	}
	return (FALSE);
}

// checking right, left, up, down
int	relative_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (right_position_is_space(map_info, cmap) == TRUE)
		return (TRUE);
	if (left_position_is_space(map_info, cmap) == TRUE)
		return (TRUE);
	if (up_position_is_space(map_info, cmap) == TRUE)
		return (TRUE);
	if (down_position_is_space(map_info, cmap) == TRUE)
		return (TRUE);
	return (FALSE);
}
