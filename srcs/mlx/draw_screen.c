/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:22:47 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/23 08:23:15 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_screen(t_vars *vars)
{
    draw_background(vars);
    draw_wall_wrapper(vars);
    mlx_put_image_to_window(vars->mlx, vars->window, vars->image->img, 0, 0);
}
