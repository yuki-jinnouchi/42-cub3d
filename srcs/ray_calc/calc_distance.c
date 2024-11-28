/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:40:17 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/28 02:41:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double  calc_player_distance(t_vec wall_pos, t_vec player_pos)
{
    double  distance;

    distance = sqrt(pow(wall_pos.x - player_pos.x, 2) + \
        pow(wall_pos.y - player_pos.y, 2));
    return (distance);
}

double calc_plane_distance(t_vec wall_pos, t_player *player)
{
    double distance;

    distance = calc_player_distance(wall_pos, player->pos) * \
                cos(atan2(wall_pos.y - player->pos.y, wall_pos.x - player->pos.x) - \
                atan2(player->dir_vec.y, player->dir_vec.x));
    return (distance);
}
