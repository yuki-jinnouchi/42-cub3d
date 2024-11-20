/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:51:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 17:32:03 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_wall(t_vars *vars)
{
    int x;
    int y;
    int i;
    int j;

    x = vars->player->pos.x;
    y = vars->player->pos.y;
    i = 0;
    while (i < 30)
    {
        j = 0;
        while (j < 30)
        {
            my_mlx_pixel_put(vars->image, x + i, y + j, 0x00000000);
            j++;
        }
        i++;
    }
    // return (SUCCESS);
}
