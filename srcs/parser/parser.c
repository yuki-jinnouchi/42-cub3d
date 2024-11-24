/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 17:28:11 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd("Error\nInvalid file name\n", 2);
		return (FALSE);
	}
	return (TRUE);
}

int	count_values(int type)
{
	static int	types[6];
	int			i;

	i = 0;
	types[type]++;
	while (types[i])
	{
		if (types[i] > 1)
		{
			ft_putstr_fd("Error\nDublicated types\n", 2);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	parser(char *file, t_map *map_info)
{
	int		fd;
	char	*line;
	int		count_info;
	int		len;

	fd = 0;
	line = NULL;
	count_info = 0;
	if (open_file(file, &fd) == FALSE)
		return (FALSE);
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	//textures and colors
	while (count_info <= 6 || line != NULL)
	{
		len = ft_strlen(line);
		if (count_info != 6 && type_identifier(line, len, map_info, &count_info) == FALSE)
			return (free_map_info_line(map_info, line), FALSE);
		if (check_img_path_and_color(map_info) == FALSE)
			return (free_map_info_line(map_info, line), FALSE);
		free(line);
		line = get_next_line(fd);
	}
	if (count_info != 6)
		return (print_error_msg_free(map_info, line, "Invalid types count\n"), FALSE);
	//map
	//skip "\n"
	if (skip_newline(line, fd, map_info) == FALSE)
		return (FALSE);
	//check map
	while(line != NULL)
	{
		
		free (line);
		line = get_next_line(fd);
	}
	return (TRUE);
}
