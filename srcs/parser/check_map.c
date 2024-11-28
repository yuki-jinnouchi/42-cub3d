/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:07:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/28 20:58:05 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_map(t_input *map_info, int fd, char *line)
{
	int	map_line_count;
	char **map_tmp_pre;
	int i;
	
    map_tmp_pre = NULL;
	map_line_count = 0;
	map_info->structure = NULL;
	line = get_next_line(fd);
	while(line != NULL)
	{
		free(map_tmp_pre);
		map_tmp_pre = map_info->structure;
		map_line_count++;
		map_info->structure = ft_calloc(sizeof(char *), map_line_count + 1);
        if (!map_info->structure)
            return (free(map_tmp_pre),print_error_msg_free(map_info, line, "map malloc error\n"), FALSE);
		i = 0;
		while(map_tmp_pre && i < map_line_count - 1)
        {

			map_info->structure[i] = map_tmp_pre[i];
            i++;
        }
        //printf("i = %d\n", i);
        //printf("i = %d, s = %s\n", i, line);
        map_info->structure[i] = line;
	printf("%d:\n", map_line_count);
	    for(int j = 0; j < map_line_count; j++)
        	printf("j = %d, s = %s\n", j, map_info->structure[j]);
	    line = get_next_line(fd);
    	// free (line);
	}
    printf("i = %d, s = %s\n", i, line);
    map_info->height = map_line_count;
	close(fd);
    return (TRUE);
}

int find_player(t_input *map_info, int *player, int i, int j)
{
    if (ft_strchr("NSEW", map_info->structure[i][j]))
    {
        //debug
        printf("pass\n");
        map_info->p = map_info->structure[i][j];
        map_info->position.x = (double)j +0.5;
        map_info->position.y = (double)i +0.5;
        (*player)++;
    }
    if (*player > 1)
    {
        printf("player = %d\n",*player);
        return (FALSE);
    }
    return (TRUE);
}

int check_map(t_input *map_info)
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
    player = 0;
    while(map_info->structure[++i])
    {
        j = -1;
        len = ft_strlen(map_info->structure[i]);
        if (i > 0)
            up_len = ft_strlen(map_info->structure[i - 1]);
        if (i < map_info->height - 1)
            down_len = ft_strlen(map_info->structure[i + 1]);
        while(map_info->structure[i][++j])
        {
            if (find_player(map_info, &player, i, j) == FALSE)
                return (print_error_msg_free_map_info(map_info, "Too many player\n"), FALSE);
            if (i == 0 || i == map_info->height - 1)
            {
                if (!ft_strchr(" 1\n", map_info->structure[i][j]))
                    return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);//上下端
            }
            else if (j == 0 || j == len - 2)
            {
                if (!ft_strchr(" 1", map_info->structure[i][j]))
                    return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE); //左右端
            }
            else
            {
                if (!ft_strchr(" 01NSEW\n", map_info->structure[i][j]))
                    return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                if (map_info->structure[i][j] == ' ')
                {
                    if (j < len - 1 && !ft_strchr(" 1\n", map_info->structure[i][j + 1])) //右
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (j > 0 && !ft_strchr(" 1\n", map_info->structure[i][j - 1])) //左
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (i > 0 && j < up_len && !ft_strchr(" 1\n", map_info->structure[i - 1][j]))//上
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                    if (i < map_info->height - 1 && j < down_len && !ft_strchr(" 1\n", map_info->structure[i + 1][j]))//下
                        return (print_error_msg_free_map_info(map_info, "Invalid map\n"), FALSE);
                }
            }
        }
    }
    if (player == 0)
        return (FALSE);
    return (TRUE);
}
