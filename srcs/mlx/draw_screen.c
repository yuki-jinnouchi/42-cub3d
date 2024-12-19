/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:22:47 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/19 01:46:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_screen(t_vars *vars)
{
	draw_background(vars);
	draw_wall(vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->image->img, 0, 0);
}
