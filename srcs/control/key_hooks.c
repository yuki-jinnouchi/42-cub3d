/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 17:17:27 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit_game(vars);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(vars, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(vars, PI);
	if (keycode == KEY_D)
		move_player(vars, (PI * 3) / 2);
	if (keycode == KEY_A)
		move_player(vars, PI / 2);
	if (keycode == KEY_RIGHT)
		rotate_player(vars, -1);
	if (keycode == KEY_LEFT)
		rotate_player(vars, 1);
	return (SUCCESS);
}

// key_press_hook
// key_release_hook
// https://github.com/JUNNETWORKS/cub3d/blob/master/key_hooks.c
