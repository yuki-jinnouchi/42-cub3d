/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:41:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 21:43:10 by hakobori         ###   ########.fr       */
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
	if (map_info->structure)
		free_array(map_info->structure);
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

void	free_texture(t_image *texture, t_vars *vars)
{
	if (texture->img)
	{
		mlx_destroy_image(vars->mlx, texture->img);
		if (texture)
			free(texture);
	}
}

void	free_all_texture(t_texture *texture, t_vars *vars)
{
	free_texture(texture->n, vars);
	free_texture(texture->s, vars);
	free_texture(texture->w, vars);
	free_texture(texture->e, vars);
	free(texture);
}
