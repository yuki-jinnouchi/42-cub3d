/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 10:51:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int load_texture(t_image *image, char *filepath, t_vars *vars)
{
    image->img = mlx_xpm_file_to_image(vars->mlx, filepath, \
        &image->width, &image->height);
    if (image->img == NULL)
        return (FAILURE);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
        &image->line_length, &image->endian);
    if(image->addr == NULL)
        return (FAILURE);
    return (SUCCESS);
}

int texture_init(t_vars *vars)
{
	t_texture *texture;

    texture = malloc(sizeof(t_texture));
    if (texture == NULL)
        return (FAILURE);
    vars->texture = texture;
    // if (load_texture(&texture->n, "./texture/North.xpm", vars) == FAILURE)
    //     return (FAILURE);
    // if (load_texture(&texture->s, "./texture/South.xpm", vars) == FAILURE)
    //     return (FAILURE);
    // if (load_texture(&texture->w, "./texture/West.xpm", vars) == FAILURE)
    //     return (FAILURE);
    // if (load_texture(&texture->e, "./texture/East.xpm", vars) == FAILURE)
    //     return (FAILURE);
    if (load_texture(&texture->n, "./texture/ws_01.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->s, "./texture/ws_03.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->w, "./texture/ws_02.xpm", vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->e, "./texture/ws_04.xpm", vars) == FAILURE)
        return (FAILURE);
    texture->floor_argb = to_uint_rgb(50, 30, 0);
    texture->ceil_argb = to_uint_rgb(160, 240, 240);
	return (SUCCESS);
}
