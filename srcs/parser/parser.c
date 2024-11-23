/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 00:26:00 by hakobori         ###   ########.fr       */
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

int	set_path_color_info(int type, t_map *map_info, char *line, int *count_info)
{
	char *trimed_line;

	if (count_values(type) == FALSE)
		return (FALSE);
	trimed_line = ft_strtrim(line, " ");
	if (trimed_line[0] == '\0')
		return (FALSE);
	if (type == NO)
		map_info->no = ft_strndup(trimed_line);
	else if (type == SO)
		map_info->so = ft_strndup(trimed_line);
	else if (type == WE)
		map_info->we = ft_strndup(trimed_line);
	else if (type == EA)
		map_info->ea = ft_strndup(trimed_line);
	else if (type == F)
		map_info->f = ft_strndup(trimed_line);
	else if (type == C)
		map_info->c = ft_strndup(trimed_line);
	*count_info += 1;
	return (TRUE);
}

int	type_identifier(char *line, int len, t_map *map_info, int *count_info)
{
	if (ft_strncmp(line, "NO", 2) == 0 && len > 2)
		if (set_path_color_info(NO, map_info, (line + 3), count_info) == FALSE)
			return (FALSE);
	if (ft_strncmp(line, "SO", 2) == 0 && len > 2)
		if (set_path_color_info(SO, map_info, (line + 3), count_info) == FALSE)
			return (FALSE);
	if (ft_strncmp(line, "WE", 2) == 0 && len > 2)
		if (set_path_color_info(WE, map_info, (line + 3), count_info) == FALSE)
			return (FALSE);
	if (ft_strncmp(line, "EA", 2) == 0 && len > 1)
		if (set_path_color_info(EA, map_info, (line + 3), count_info) == FALSE)
			return (FALSE);
	if (ft_strncmp(line, "F", 1) == 0 && len > 1)
		if (set_path_color_info(F, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	if (ft_strncmp(line, "C", 1) == 0 && len > 1)
		if (set_path_color_info(C, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	if(ft_strncmp(line, "\n", 1) != 0)
		return (t_putstr_fd("Error\nInvalid type name\n", 2), FALSE);
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
	free (line);
	if (count_info != 6)
		return (print_error_msg_free(map_info, "Invalid types count\n"), FALSE);
	return (TRUE);
}
