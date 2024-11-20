/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_degrees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 04:27:18 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/20 17:30:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// double deg_to_rad(double deg)
// {
//     return ((deg * PI) / 180);
// }

// double    add_deg_to_rad(double deg, double rad)
// {
//     double new_rad;

//     new_rad = deg_to_rad(deg);
//     rad += new_rad;
//     return (round_rad(rad));
// }

// double   round_deg(double deg)
// {
//     if (deg < 0)
//         deg += 360;
//     if (deg >= 360)
//         deg -= 360;
//     return (deg);
// }

double  round_rad(double rad)
{
    if (rad < 0)
        rad += 2 * PI;
    if (rad >= 2 * PI)
        rad -= 2 * PI;
    return (rad);
}
double add_rad(double rad1, double rad2)
{
    double new_rad;

    new_rad = rad1 + rad2;
    new_rad = round_rad(new_rad);
    return (new_rad);
}
