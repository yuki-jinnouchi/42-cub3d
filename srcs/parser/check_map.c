/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 22:50:52 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_not_space_or_next_line(t_input *map_info, t_check_map *cmap)
{
	if (cmap->j < cmap->len - 1 && ft_strchr(" \n",
			map_info->structure[cmap->i][cmap->j + 1]))
		return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
			FALSE);
	if (cmap->j > 0 && ft_strchr(" \n", map_info->structure[cmap->i][cmap->j
			- 1]))
		return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
			FALSE);
	if (cmap->i > 0 && cmap->j < cmap->up_len && ft_strchr(" \n",
			map_info->structure[cmap->i - 1][cmap->j]))
		return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
			FALSE);
	if (cmap->i < map_info->height - 1 && cmap->j < cmap->down_len
		&& ft_strchr(" \n", map_info->structure[cmap->i + 1][cmap->j]))
		return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
			FALSE);
	return (TRUE);
}

void	check_map_init(t_check_map *cmap)
{
	cmap->i = -1;
	cmap->up_len = 0;
	cmap->down_len = 0;
	cmap->player = 0;
}

void	check_map_set_j_lens(t_check_map *cmap, t_input *map_info)
{
	cmap->j = -1;
	cmap->len = ft_strlen(map_info->structure[cmap->i]);
	if (cmap->i > 0)
		cmap->up_len = ft_strlen(map_info->structure[cmap->i - 1]);
	if (cmap->i < map_info->height - 1)
		cmap->down_len = ft_strlen(map_info->structure[cmap->i + 1]);
}

int	check_map_details(t_check_map *cmap, t_input *map_info)
{
	if (cmap->i == 0 || cmap->i == map_info->height - 1)
	{
		if (!ft_strchr(" 1\n", map_info->structure[cmap->i][cmap->j]))
			return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
				FALSE);
	}
	else if (cmap->j == 0 || cmap->j == cmap->len - 2)
	{
		if (!ft_strchr(" 1", map_info->structure[cmap->i][cmap->j]))
			return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
				FALSE);
	}
	else
	{
		if (!ft_strchr(" 01NSEW\n", map_info->structure[cmap->i][cmap->j]))
			return (print_error_msg_free_map_info(map_info, "Invalid map\n"),
				FALSE);
		if (ft_strchr("0NSEW", map_info->structure[cmap->i][cmap->j]))
			if (is_not_space_or_next_line(map_info, cmap) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

int	check_map(t_input *map_info)
{
	t_check_map	cmap;

	check_map_init(&cmap);
	while (map_info->structure[++cmap.i])
	{
		check_map_set_j_lens(&cmap, map_info);
		while (map_info->structure[cmap.i][++cmap.j])
		{
			if (find_player(map_info, &cmap.player, cmap.i, cmap.j) == FALSE)
				return (print_error_msg_free_map_info(map_info,
						"Too many player\n"), FALSE);
			if (check_map_details(&cmap, map_info) == FALSE)
				return (FALSE);
		}
	}
	if (cmap.player == 0)
		return (print_error_msg_free_map_info(map_info, "no player\n"), FALSE);
	return (TRUE);
}
