/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 20:55:13 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int skip_newline(char *line, int fd, t_input *map_info)
{
	while(line != NULL && ft_strncmp(line,"\n", 1) == 0)
	{
		free (line);
		line = get_next_line(fd);
		if (line == NULL)
			return (print_error_msg_free(map_info, line, "Invalid map\n"),FALSE);
	}
    return (TRUE);
}
