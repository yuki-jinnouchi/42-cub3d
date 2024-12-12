/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:50:01 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 22:50:13 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(t_input *map_info, int *player, int i, int j)
{
	if (ft_strchr("NSEW", map_info->structure[i][j]))
	{
		map_info->dir = map_info->structure[i][j];
		map_info->position.x = (double)j + 0.5;
		map_info->position.y = (double)i + 0.5;
		(*player)++;
	}
	if (*player > 1)
		return (FALSE);
	return (TRUE);
}
