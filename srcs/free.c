/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:41:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 16:44:14 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char **head)
{
	int	i;

	i = 0;
	while (head[i])
		free(head[i++]);
	free(head);
}

void	free_color(t_color *color)
{
	free(color);
}

void free_map_info(t_map *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
	free_color(map_info->f_detail);
	free_color(map_info->c_detail);
	free_2d_array(map_info->structure);
}

void free_map_info_line(t_map *map_info, char *line)
{
    free_map_info(map_info);
    free(line);
}
