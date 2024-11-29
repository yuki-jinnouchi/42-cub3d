/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:08:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 09:38:02 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + \
        (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int rgb_to_16argb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

