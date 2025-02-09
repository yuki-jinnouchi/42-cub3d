/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:42:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/20 18:14:34 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exec_game(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->window, 17, 1L << 17, exit_game, vars);
	mlx_loop_hook(vars->mlx, refresh_screen, vars);
	mlx_loop(vars->mlx);
}
