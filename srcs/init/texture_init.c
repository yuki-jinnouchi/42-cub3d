/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 02:30:01 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int texture_init(t_vars *vars)
{
	t_texture *texture;

    texture = malloc(sizeof(t_texture));
    if (texture == NULL)
        return (FAILURE);
    vars->texture = texture;
    texture->tile_size = TILE_SIZE;
    load_image(&texture->n, "./sprite/NO.xpm", vars);
    load_image(&texture->s, "./sprite/SO.xpm", vars);
    load_image(&texture->w, "./sprite/WE.xpm", vars);
    load_image(&texture->e, "./sprite/EA.xpm", vars);
    texture->floor_argb = rgb_to_16argb(50, 30, 0);
    texture->ceil_argb = rgb_to_16argb(160, 240, 240);
	return (SUCCESS);
}
