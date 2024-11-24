/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:46:29 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 16:45:19 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_error_msg_free(t_map *map_info, char *line, char *error_msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error_msg,2);
    free_map_info(map_info);
    free(line);
}

void    print_error_msg(char *error_msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error_msg,2);

}