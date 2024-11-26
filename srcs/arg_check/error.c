/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:46:29 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/26 20:54:38 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_error_msg_free(t_input *map_info, char *line, char *error_msg)
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

void    print_error_msg_free_map_info(t_input *map_info, char *error_msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error_msg,2);
    free_map_info(map_info);
}
