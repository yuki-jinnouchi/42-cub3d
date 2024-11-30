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

uint32_t	to_uint_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

uint32_t	get_image_color(t_image image, int x, int y)
{
	uint32_t	*color;

	color = (uint32_t *)(image.addr + \
		(y * image.line_length) + \
		(x * image.bits_per_pixel / 8));
	return (*color);
}

uint32_t	get_image_color_by_ratio(\
	t_image image, double x_ratio, double y_ratio)
{
	uint32_t	color;
	int			x;
	int			y;

	x = (int)(image.width * x_ratio);
	y = (int)(image.height * y_ratio);
	color = get_image_color(image, x, y);
	return (color);
}
