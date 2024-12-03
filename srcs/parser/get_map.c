/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:46:53 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 22:51:10 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_init(t_input *map_info, char ***map_tmp_pre,
		int *map_line_count)
{
	*map_tmp_pre = NULL;
	*map_line_count = 0;
	map_info->structure = NULL;
}

int	get_map(t_input *map_info, int fd, char *line)
{
	int		map_line_count;
	char	**map_tmp_pre;
	int		i;

	get_map_init(map_info, &map_tmp_pre, &map_line_count);
	while (line != NULL)
	{
		map_tmp_pre = map_info->structure;
		map_line_count++;
		map_info->structure = ft_calloc(sizeof(char *), map_line_count + 1);
		if (!map_info->structure)
			return (free(map_tmp_pre), print_error_msg_free(map_info, line,
					"map malloc error\n"), FALSE);
		i = 0;
		while (map_tmp_pre && i < map_line_count - 1)
		{
			map_info->structure[i] = map_tmp_pre[i];
			i++;
		}
		map_info->structure[i] = line;
		line = get_next_line(fd);
		free(map_tmp_pre);
	}
	map_info->height = map_line_count;
	return (close(fd), TRUE);
}
