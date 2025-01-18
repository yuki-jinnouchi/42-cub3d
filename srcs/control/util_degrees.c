/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_degrees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:27:18 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 16:37:18 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (PI * (deg / 180));
}

double	round_rad(double rad)
{
	while (rad < 0)
		rad += 2 * PI;
	while (rad >= 2 * PI)
		rad -= 2 * PI;
	return (rad);
}

double	add_rad(double rad1, double rad2)
{
	double	new_rad;

	new_rad = rad1 + rad2;
	new_rad = round_rad(new_rad);
	return (new_rad);
}

t_vec	dir_to_vec(double rad_dir)
{
	t_vec	new_vec;

	new_vec.x = cos(rad_dir - (PI / 2));
	new_vec.y = sin(rad_dir - (PI / 2));
	return (new_vec);
}
