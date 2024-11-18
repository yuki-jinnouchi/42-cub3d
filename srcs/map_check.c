/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/17 20:33:56 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_map_info(char *file_name, t_map *map_info)
{
	int	fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nInvalid file name\n");
		return (FALSE);
	}
	set_map_details(fd, map_info, line);
	return (TRUE);
}

int	map_check(int argc, char **argv, t_map *map_info)
{
	if (arg_check(argc, argv) == FALSE)
		return (FALSE);
	if (set_map_info(argv[1], map_info) == FALSE)
		return (FALSE);
	if (type_identifier_check(argv[1]) == FALSE)
		return (FALSE);
	if (foolfill_check(argv[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}
