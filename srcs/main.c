	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/16 17:10:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(char argc, char **argv)
{
	if(arg_check(argv) == FALSE)
		return (0);
	if(map_check(argv) == FALSE)
		return (0);
	if(map_parse(argv) == FALSE)
		return (0);
}
