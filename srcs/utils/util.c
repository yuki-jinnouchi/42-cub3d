/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:16:43 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 18:07:49 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	abs_double(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
