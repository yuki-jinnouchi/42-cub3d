/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:50:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/01/18 17:57:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	abs_double(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	abs_int(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
