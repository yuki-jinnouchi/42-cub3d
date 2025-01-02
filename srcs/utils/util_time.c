/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:14:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/12/25 06:51:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// screen time diff is over 1/FRAME_RATE sec
int	is_screen_renew(t_timeval *current, t_timeval *last)
{
	long	sec_diff;
	long	usec_diff;

	sec_diff = current->tv_sec - last->tv_sec;
	usec_diff = current->tv_usec - last->tv_usec;
	if (sec_diff > 1)
		return (TRUE);
	if ((sec_diff * 1000000 + usec_diff) >= (1000000 / FRAME_RATE))
		return (TRUE);
	return (FALSE);
}
