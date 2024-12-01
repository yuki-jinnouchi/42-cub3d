/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/01 21:41:47 by hakobori         ###   ########.fr       */
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
			return (print_error_msg_free(map_info, *line, "Invalid map\n"),
				FALSE);
	}
	return (TRUE);
}
