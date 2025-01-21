/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path_and_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 21:58:21 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_values(int type)
{
	static int	types[6];
	int			i;

	i = 0;
	types[type] += 1;
	while (i < 6)
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

int	check_img_path_and_color(t_input *map_info)
{
	void	*mlx;

	mlx = mlx_init();
	if (check_img_path_exist_all(map_info, mlx) == FALSE)
		return (FALSE);
	if (check_color_valid_fc(map_info, mlx) == FALSE)
		return (FALSE);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	return (TRUE);
}

int	set_path_color_info(int type, t_input *map_info, char *line,
		int *count_info)
{
	char	*trimed_line;

	if (count_values(type) == FALSE)
		return (FALSE);
	trimed_line = ft_strtrim(line, " \n");
	if (trimed_line[0] == '\0')
		return (FALSE);
	if (type == NO)
		map_info->no = trimed_line;
	else if (type == SO)
		map_info->so = trimed_line;
	else if (type == WE)
		map_info->we = trimed_line;
	else if (type == EA)
		map_info->ea = trimed_line;
	else if (type == F)
		map_info->f = trimed_line;
	else if (type == C)
		map_info->c = trimed_line;
	*count_info += 1;
	return (TRUE);
}

int	texture_identifier(char *line, int len, t_input *map_info, int *count_info)
{
	if (ft_strncmp(line, "NO", 2) == 0 && len > 2)
	{
		if (set_path_color_info(NO, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	}
	else if (ft_strncmp(line, "SO", 2) == 0 && len > 2)
	{
		if (set_path_color_info(SO, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 && len > 2)
	{
		if (set_path_color_info(WE, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	}
	else if (ft_strncmp(line, "EA", 2) == 0 && len > 1)
	{
		if (set_path_color_info(EA, map_info, (line + 2), count_info) == FALSE)
			return (FALSE);
	}
	else
		return (NEXT);
	return (TRUE);
}

int	type_identifier(char *line, int len, t_input *map_info, int *count_info)
{
	int	texture_identifier_ret;

	texture_identifier_ret = texture_identifier(line, len, map_info,
			count_info);
	if (texture_identifier_ret == TRUE)
		return (TRUE);
	else if (texture_identifier_ret == FALSE)
		return (FALSE);
	if (ft_strncmp(line, "F", 1) == 0 && len > 1)
	{
		if (set_path_color_info(F, map_info, (line + 1), count_info) == FALSE)
			return (FALSE);
	}
	else if (ft_strncmp(line, "C", 1) == 0 && len > 1)
	{
		if (set_path_color_info(C, map_info, (line + 1), count_info) == FALSE)
			return (FALSE);
	}
	else if (ft_strncmp(line, "\n", 1) != 0)
	{
		ft_putstr_fd("Error\nInvalid type name\n", 2);
		return (FALSE);
	}
	return (TRUE);
}
