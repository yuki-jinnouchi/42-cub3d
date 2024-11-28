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
    t_color color;

    texture = malloc(sizeof(t_texture));
    if (texture == NULL)
        return (FAILURE);
    vars->texture = texture;
    if (load_texture(&texture->n, vars->input->no, vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->s, vars->input->so, vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->w, vars->input->we, vars) == FAILURE)
        return (FAILURE);
    if (load_texture(&texture->e, vars->input->ea, vars) == FAILURE)
        return (FAILURE);
    color = vars->input->f_detail;
    texture->floor_argb = rgb_to_16argb(color.r, color.g, color.b);
    color = vars->input->c_detail;
    texture->ceil_argb = rgb_to_16argb(color.r, color.g, color.b);
	return (SUCCESS);
}
