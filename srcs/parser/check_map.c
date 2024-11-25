/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 00:19:32 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_map(t_map *map_info, int fd, char *line)
{
	int	map_line_count;
	char **map_tmp_pre;
	int i;
	
	map_line_count = 0;
	map_info->structure = NULL;
	while(line != NULL)
	{
		map_tmp_pre = map_info->structure;
		map_line_count++;
		map_info->structure = ft_calloc(sizeof(char *), map_line_count);
        if (!map_info->structure)
            return (print_error_msg_free(map_info, line, "map malloc error\n"), FALSE);
		i = -1;
		while(map_tmp_pre && map_tmp_pre[++i])
			map_info->structure[i] = map_tmp_pre[i];
		map_info->structure[++i] = line;
		free(map_tmp_pre);
		free (line);
		line = get_next_line(fd);
	}
    map_info->height = map_line_count;
	close(fd);
    return (TRUE);
}

int find_player(t_map *map_info, int *player, int i, int j)
{
    if (ft_strrchr("NSEW", map_info->structure[i][j]))
    {
        map_info->p = map_info->structure[i][j];
        (*player)++;
    }
    if (*player > 1)
        return (FALSE);
    return (TRUE);
}

int check_map(t_map *map_info)
{
    int i;
    int j;
    int player;
    int len;
    int up_len;
    int down_len;


    i = -1;
    up_len = 0;
    down_len = 0;
    while(map_info->structure[++i])
    {
        j = -1;
        len = map_info->structure[i];
        if (i > 0)
            up_len = ft_strlen(map_info->structure[i - 1]);
        if (i < map_info->height)
            down_len = ft_strlen(map_info->structure[i + 1]);
        while(map_info->structure[i][++j])
        {
            if (find_player(map_info, &player, i, j) == FALSE)
                return (print_error_msg_free_map_info(map_info, "Too many player\n"), FALSE);
            if (i == 0 || i == map_info->height - 1)
                if (!ft_strrchr(" 1\n", map_info->structure[i][j]))
                    return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
            else
            {
                if (!ft_strrchr(" 01NSEW\n", map_info->structure[i][j]))
                    return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                if (map_info->structure[i][j] == ' ')
                {
                    if (j < len - 1 && !ft_strrchr(" 1\n", map_info->structure[i][j + 1])) //右
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (j > 0 && !ft_strrchr(" 1\n", map_info->structure[i][j - 1])) //左
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (i > 0 && j < up_len && !ft_strrchr(" 1\n", map_info->structure[i - 1][j]))//上
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (i < map_info->height - 1 && j < down_len && !ft_strrchr(" 1\n", map_info->structure[i + 1][j]))//下
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                }
            }
        }
    }
    return (TRUE);
}
