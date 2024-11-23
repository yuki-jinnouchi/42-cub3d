/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path_and_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 00:26:52 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_img_path_and_color(t_map *map_info)
{
    if (check_img_path_exist(map_info->no) == FALSE)
        return (print_error_msg("NO invalid path\n"), FALSE);
    if (check_img_path_exist(map_info->so) == FALSE)
        return (print_error_msg("SO invalid path\n"), FALSE);
    if (check_img_path_exist(map_info->we) == FALSE)
        return (print_error_msg("WE invalid path\n"), FALSE);
    if (check_img_path_exist(map_info->ea) == FALSE)
        return (print_error_msg("EA invalid path\n"), FALSE);
    if (check_color_valid(map_info->f) == FALSE)
        return (print_error_msg("F invalid color info\n"), FALSE);
    if (check_color_valid(map_info->c) == FALSE)
        return (print_error_msg("C invalid color info\n"), FALSE);
    return (TRUE);
}
