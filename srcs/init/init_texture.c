/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:09 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 07:09:35 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_image **image, char *filepath, t_vars *vars)
{
	t_image	*ptr;

	(*image) = malloc(sizeof(t_image));
	ptr = (*image);
	if (*image == NULL)
		return (FAILURE);
	ptr->img = mlx_xpm_file_to_image(vars->mlx, filepath, \
		&ptr->width, &ptr->height);
	if (ptr->img == NULL)
		return (FAILURE);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, \
		&ptr->line_length, &ptr->endian);
	if (ptr->addr == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	texture_init(t_vars *vars)
{
	t_texture	*texture;
	t_color		color;

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
	texture->floor_argb = to_uint_rgb(color.r, color.g, color.b);
	color = vars->input->c_detail;
	texture->ceil_argb = to_uint_rgb(color.r, color.g, color.b);
	return (SUCCESS);
}
