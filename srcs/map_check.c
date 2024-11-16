/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/16 17:19:31 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//pathの先にあるファイルが存在するか確認する関数必要

void	set_map_details(int fd, t_map *map_info, char *line)
{
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] == 'R')
			set_resolution(line, map_info);
		else if (line[0] == 'N' && line[1] == 'O')
			set_texture(line, map_info, 'N');
		else if (line[0] == 'S' && line[1] == 'O')
			set_texture(line, map_info, 'S');
		else if (line[0] == 'W' && line[1] == 'E')
			set_texture(line, map_info, 'W');
		else if (line[0] == 'E' && line[1] == 'A')
			set_texture(line, map_info, 'E');
		else if (line[0] == 'F')
			set_color(line, map_info, 'F');
		else if (line[0] == 'C')
			set_color(line, map_info, 'C');
		else if (line[0] == '1')
			set_structure(line, map_info);
		else if (line[0] == '\0')
			continue;
		else
			return (printf("Error\nInvalid map file\n"),FALSE);
		free(line);
	}
}

int set_map_info(char *file_name, t_map *map_info)
{
	int fd;
	char *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nInvalid file name\n");
		return (FALSE);
	}
	set_map_details(fd, map_info, line);
	return (TRUE);
}

int map_check(int argc, char **argv, t_map *map_info)
{
	if(arg_check(argc, argv) == FALSE)
		return (FALSE);
	if(set_map_info(argv[1], map_info) == FALSE)
		return (FALSE);
	if(type_identifier_check(argv[1]) == FALSE)
		return (FALSE);
	if(foolfill_check(argv[1]) == FALSE)
		return (FALSE);
	return(TRUE);
}
