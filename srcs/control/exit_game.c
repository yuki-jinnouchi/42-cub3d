/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:13:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 01:54:39 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_texture(t_texture *texture, t_vars *vars)
{
	if (texture->n.img)
		mlx_destroy_image(vars->mlx, texture->n.img);
	if (texture->s.img)
		mlx_destroy_image(vars->mlx, texture->s.img);
	if (texture->w.img)
		mlx_destroy_image(vars->mlx, texture->w.img);
	if (texture->e.img)
		mlx_destroy_image(vars->mlx, texture->e.img);
	free(texture);
	return (SUCCESS);
}

int	exit_game(t_vars *vars)
{
	free(vars->filename);
	free_array(vars->map->structure);
	if (vars->map)
		free(vars->map);
	if (vars->texture)
		free_texture(vars->texture, vars);
	if (vars->image)
		mlx_destroy_image(vars->mlx, vars->image->img);
	free(vars->image);
	mlx_destroy_window(vars->mlx, vars->window);
	free(vars->mlx);
	exit(SUCCESS);
	return (SUCCESS);
}
