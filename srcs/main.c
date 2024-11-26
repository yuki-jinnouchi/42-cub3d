/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 20:28:12 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_vars	*vars;
	t_map	map_info;
	t_map	*map_info_ptr;

	map_info_ptr = &map_info;
	ft_bzero(map_info_ptr, sizeof(t_map));
	if(arg_check(argc, argv) == FALSE)
		return (FAILURE);
	if(parse(argv, map_info_ptr) == FALSE)
		return (FAILURE);
	// vars = vars_init(argv);
	// if (vars == NULL)
	// {
	// 	printf("Error\n");
	// 	return (FAILURE);
	// }
	//exec_game(vars);
	return (SUCCESS);
}
