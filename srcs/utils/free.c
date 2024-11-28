/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:41:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/28 23:55:02 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_2d_array(char **head)
{
	int	i;

	i = 0;
	while(head[i])
	{
		free(head[i]);
		i++;
	}
	free (head);
}

void	free_color(t_color *color)
{
	free(color);
}

void free_map_info(t_input *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
//	free_color(map_info->f_detail);
//	free_color(map_info->c_detail);
	if (map_info->structure)
		free_2d_array(map_info->structure);
}

void free_map_info_after_init(t_input *map_info)
{
	free(map_info->no);
	free(map_info->so);
	free(map_info->we);
	free(map_info->ea);
	free(map_info->f);
	free(map_info->c);
//	free_color(map_info->f_detail);
//	free_color(map_info->c_detail);
}

void free_map_info_line(t_input *map_info, char *line)
{
    free_map_info(map_info);
    // free(line);
	(void)line;
}

size_t	ft_strlen_null_gard(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
