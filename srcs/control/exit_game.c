/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:13:53 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 06:08:08 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_vars *vars)
{
	free(vars->filename);
	free(vars->wall_heights);
	free(vars->player);
	free_array(vars->map->structure);
	free_if_exist(vars->map);
	if (vars->texture)
		free_all_texture(vars->texture, vars);
	if (vars->image)
		mlx_destroy_image(vars->mlx, vars->image->img);
	free(vars->image);
	mlx_destroy_window(vars->mlx, vars->window);
	free(vars->mlx);
	free_if_exist(vars);
	exit(SUCCESS);
	return (SUCCESS);
}
