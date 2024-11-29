/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 08:10:43 by yjinnouc         ###   ########.fr       */
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
    if (load_image(&texture->n, "./texture/North.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_image(&texture->s, "./texture/South.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_image(&texture->w, "./texture/West.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_image(&texture->e, "./texture/East.xpm", vars) == FAILURE)
        return (FAILURE);
    texture->floor_argb = rgb_to_16argb(50, 30, 0);
    texture->ceil_argb = rgb_to_16argb(160, 240, 240);
	return (SUCCESS);
}
