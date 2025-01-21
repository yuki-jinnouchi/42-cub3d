/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:41:40 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 18:05:46 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_image *texture, t_vars *vars)
{
	if (texture->img)
	{
		mlx_destroy_image(vars->mlx, texture->img);
		free_if_exist(texture);
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
