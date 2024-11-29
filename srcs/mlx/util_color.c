/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 10:10:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	to_uint_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	get_image_color(t_image image, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)(image.addr + \
		(y * image.line_length) + \
		(x * image.bits_per_pixel / 8));
	return (*color);
}

unsigned int	get_image_color_by_ratio(\
	t_image image, double x_ratio, double y_ratio)
{
	unsigned int	color;
	int				x;
	int				y;

	x = (int)(image.width * x_ratio);
	y = (int)(image.height * y_ratio);
	color = get_image_color(image, x, y);
	return (color);
}
