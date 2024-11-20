/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/20 05:03:47 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_vars	*vars;

	if(arg_check(argc, argv) == FALSE)
	{
		printf("Error\n");
		return (FAILURE);
	}
	vars = vars_init(argv);
	if (vars == NULL)
	{
		printf("Error\n");
		return (FAILURE);
	}
	exec_game(vars);
	return (SUCCESS);
}
