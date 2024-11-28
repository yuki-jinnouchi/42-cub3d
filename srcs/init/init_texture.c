/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/28 23:45:33 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int texture_init(t_vars *vars)
{
	t_texture *texture;
    t_color color;

    texture = malloc(sizeof(t_texture));
    if (texture == NULL)
        return (FAILURE);
    vars->texture = texture;
    texture->tile_size = TILE_SIZE;
    load_image(&texture->n, vars->input->no, vars);
    load_image(&texture->s, vars->input->so, vars);
    load_image(&texture->w, vars->input->we, vars);
    load_image(&texture->e, vars->input->ea, vars);
    color = vars->input->f_detail;
    texture->floor_argb = rgb_to_16argb(color.r, color.g, color.b);
    color = vars->input->c_detail;
    texture->ceil_argb = rgb_to_16argb(color.r, color.g, color.b);
	return (SUCCESS);
}
