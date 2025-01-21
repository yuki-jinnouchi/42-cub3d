/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 22:14:12 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_newline(char **line, int fd, t_input *map_info)
{
	*line = get_next_line(fd);
	while (*line != NULL && ft_strncmp(*line, "\n", 1) == 0)
	{
		free(*line);
		*line = get_next_line(fd);
		if (*line == NULL)
		{
			print_error_msg_free(map_info, *line, "Invalid map\n");
			return (FALSE);
		}
	}
	return (TRUE);
}
