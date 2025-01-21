/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 22:56:01 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_init(t_check_map *cmap)
{
	cmap->y = -1;
	cmap->x = -1;
	cmap->player = 0;
	cmap->len = 0;
	cmap->up_len = 0;
	cmap->down_len = 0;
}

void	check_map_set_x_lens(t_check_map *cmap, t_input *map_info)
{
	cmap->x = -1;
	cmap->len = ft_strlen(map_info->structure[cmap->y]);
	if (cmap->y > 0)
		cmap->up_len = ft_strlen(map_info->structure[cmap->y - 1]);
	if (cmap->y < map_info->height - 1)
		cmap->down_len = ft_strlen(map_info->structure[cmap->y + 1]);
}

int	is_edge(t_check_map *cmap, t_input *map_info)
{
	if (cmap->y == 0)
		return (TRUE);
	else if (cmap->y == map_info->height - 1)
		return (TRUE);
	else if (cmap->x == 0)
		return (TRUE);
	else if (cmap->x == cmap->len - 2)
		return (TRUE);
	return (FALSE);
}

int	check_map_details(t_check_map *cmap, t_input *map_info)
{
	if (is_edge(cmap, map_info) == TRUE)
	{
		if (!ft_strchr(" 1\n", map_info->structure[cmap->y][cmap->x]))
		{
			print_error_msg_free_map_info_2d(map_info, "Invalid map\n");
			return (FALSE);
		}
	}
	else
	{
		if (!ft_strchr(" 01NSEW\n", map_info->structure[cmap->y][cmap->x]))
		{
			print_error_msg_free_map_info_2d(map_info, "Invalid map\n");
			return (FALSE);
		}
		if (ft_strchr("0NSEW", map_info->structure[cmap->y][cmap->x]))
		{
			if (relative_position_is_space(map_info, cmap) == TRUE)
			{
				print_error_msg_free_map_info(map_info, "Invalid map\n");
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

int	check_map(t_input *map_info)
{
	t_check_map	cmap;

	check_map_init(&cmap);
	while (map_info->structure[++cmap.y])
	{
		check_map_set_x_lens(&cmap, map_info);
		while (map_info->structure[cmap.y][++cmap.x])
		{
			if (find_player(map_info, &cmap.player, cmap.y, cmap.x) == FALSE)
			{
				print_error_msg_free_map_info(map_info, "Too many player\n");
				return (FALSE);
			}
			if (check_map_details(&cmap, map_info) == FALSE)
				return (FALSE);
		}
	}
	if (cmap.player == 0)
	{
		print_error_msg_free_map_info(map_info, "no player\n");
		return (FALSE);
	}
	return (TRUE);
}
