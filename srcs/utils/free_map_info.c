/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:05:08 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/21 21:46:10 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_info(t_input *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
	free_if_exist(map_info->structure);
}

void	free_map_info_after_init(t_input *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
}

void	free_map_info_map_structure(t_input *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
	free_array(map_info->structure);
}
