/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/28 21:05:18 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int set_int_color(int type, char *color, t_color *color_detail)
{
    long    tmp;
    int i;

    i = 0;
    while (color[i])
        i++;
    if (i > 3)
        return (FALSE);
    tmp = ft_atoi(color);
    if (tmp < 0 || tmp > 255)
        return (FALSE);
    if (type == R)
        color_detail->r = tmp;
    if (type == G)
        color_detail->g = tmp;
    if (type == B)
    color_detail->b = tmp;
    return (TRUE);
}

int set_color_detail(char **split_color_info,t_color *color_detail)
{
    int i;
    char *tmp;

    i = 0;

    while(split_color_info[i])
    {
        tmp = split_color_info[i];
        split_color_info[i] = ft_strtrim(tmp," ");
        free (tmp);
        i++;
    }
    if (i != 3)
        return (free_array(split_color_info), FALSE);
    if(set_int_color(R, split_color_info[0], color_detail) == FALSE)
        return (free_array(split_color_info), FALSE);
    if(set_int_color(G, split_color_info[1], color_detail) == FALSE)
        return (free_array(split_color_info), FALSE);
    if(set_int_color(B, split_color_info[2], color_detail) == FALSE)
        return (free_array(split_color_info), FALSE);
    return (free_array(split_color_info), TRUE);
}

int check_color_valid(char *color_info, t_input *map_info, int type)
{
    t_color *color_detail;
    char **split_color_info;

    color_detail = ft_calloc(sizeof(t_color), 1);
    if (!color_detail)
        return (FALSE);
    split_color_info = ft_split(color_info, ',');
    if (!split_color_info)
        return (free (color_detail), FALSE);
    if (set_color_detail(split_color_info, color_detail) == FALSE)
        return (free(color_detail), FALSE);
    if (type == F)
        map_info->f_detail = color_detail;
    else if (type == C)
        map_info->c_detail = color_detail;
    else
        return (free(color_detail), FALSE);
    return (TRUE);
}
