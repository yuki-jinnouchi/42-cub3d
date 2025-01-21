/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 22:56:06 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(int c)
{
	if (ft_strchr(" \n", c))
		return (TRUE);
	return (FALSE);
}

int	relative_position_is_space(t_input *map_info, t_check_map *cmap)
{
	if (cmap->x < cmap->len - 1
		&& ft_isspace(map_info->structure[cmap->y][cmap->x + 1]))
		return (TRUE);
	if (cmap->x > 0 && ft_isspace(map_info->structure[cmap->y][cmap->x - 1]))
		return (TRUE);
	if (cmap->y > 0 && cmap->x < cmap->up_len
		&& ft_isspace(map_info->structure[cmap->y - 1][cmap->x]))
		return (TRUE);
	if (cmap->y < map_info->height - 1 && cmap->x < cmap->down_len
		&& ft_isspace(map_info->structure[cmap->y + 1][cmap->x]))
		return (TRUE);
	return (FALSE);
}
