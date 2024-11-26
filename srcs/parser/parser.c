/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 21:07:10 by hakobori         ###   ########.fr       */
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

int set_textures_and_colors(char *line, int fd, t_input *map_info)
{
	int		count_info;
	int		len;
	
	count_info = 0;
	while (count_info <= 6 || line != NULL)
	{
		len = ft_strlen_null_gard(line);
		if (count_info != 6 && type_identifier(line, len, map_info, &count_info) == FALSE)
			return (free_map_info_line(map_info, line), FALSE);
		if (check_img_path_and_color(map_info) == FALSE)
			return (free_map_info_line(map_info, line), FALSE);
		free(line);
		line = get_next_line(fd);
	}
	if (count_info != 6)
		return (print_error_msg_free(map_info, line, "Invalid types count\n"), FALSE);
	return (TRUE);
}

int	parser(char *file, t_input *map_info)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (open_file(file, &fd) == FALSE)
		return (FALSE);
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	if (set_textures_and_colors(line, fd, map_info) == FALSE)
		return (FALSE);
	if (skip_newline(line, fd, map_info) == FALSE)
		return (FALSE);
	if (get_map(map_info, fd, line) == FALSE)
		return (FALSE);
	if (check_map(map_info) == FALSE)
		return (FALSE);
	if (skip_newline(line, fd, map_info) == FALSE)
		return (FALSE);
	return (TRUE);
}
