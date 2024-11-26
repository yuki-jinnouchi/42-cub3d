/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:27 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 21:42:22 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_vars	*vars;
	t_input	map_info;
	t_input	*map_info_ptr;

	map_info_ptr = &map_info;
	ft_bzero(map_info_ptr, sizeof(t_input));
	if(arg_check(argc, argv) == FALSE)
		return (FAILURE);
	if(parser(argv[1], map_info_ptr) == FALSE)
		return (FAILURE);
	vars = vars_init(argv);
	if (vars == NULL)
	{
		printf("Error\n");
		return (FAILURE);
	}
	exec_game(vars);
	return (SUCCESS);
}
