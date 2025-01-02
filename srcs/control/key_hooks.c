/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/20 16:47:18 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// key_press_hook
// key_release_hook
// https://github.com/JUNNETWORKS/cub3d/blob/master/key_hooks.c
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit_game(vars);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(vars, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(vars, 180);
	if (keycode == KEY_D)
		move_player(vars, 90);
	if (keycode == KEY_A)
		move_player(vars, 270);
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		rotate_player(vars, 1);
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		rotate_player(vars, -1);
	return (SUCCESS);
}
