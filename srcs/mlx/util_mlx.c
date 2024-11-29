/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:08:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 08:01:52 by yjinnouc         ###   ########.fr       */
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

int load_image(t_image *image, char *filepath, t_vars *vars)
{
    // image = malloc(sizeof(t_image));
    // if (image == NULL)
    //     return (FAILURE);
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
