/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:09:12 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 18:10:33 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	refresh_screen(t_vars *vars)
{
	t_timeval	t_current;

	gettimeofday(&t_current, NULL);
	if (is_screen_renew(&t_current, &vars->last_refresh))
	{
		mlx_put_image_to_window(vars->mlx, vars->window, \
			vars->image->img, 0, 0);
		draw_refresh_img(vars);
		if (t_current.tv_sec - vars->last_refresh.tv_sec > 0)
		{
			// printf("FPS: %d\n", vars->refresh_rate);
			vars->refresh_rate = 1;
		}
		else
			vars->refresh_rate++;
		vars->last_refresh = t_current;
	}
	return (0);
}
