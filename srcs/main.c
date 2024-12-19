/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/19 01:37:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_input	map_info;
	t_input	*map_info_ptr;

	map_info_ptr = &map_info;
	ft_bzero(map_info_ptr, sizeof(t_input));
	if (arg_check(argc, argv) == FALSE)
		return (FAILURE);
	if (parser(argv[1], map_info_ptr) == FALSE)
		return (FAILURE);
	if (vars_init(argv, map_info_ptr, &vars) == FAILURE)
	{
		printf("Error\n");
		return (FAILURE);
	}
	exec_game(&vars);
	return (SUCCESS);
}
