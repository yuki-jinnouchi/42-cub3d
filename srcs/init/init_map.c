/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:45:42 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/11/29 13:10:10 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	map_convert(t_map *map, t_vars *vars)
// {
//     return (SUCCESS);
// }

// int map_read_file(t_map *map, t_vars *vars)
// {

//     map->fd_inputfile = open(vars->filename, O_RDONLY);
//     // if (fd == -1)
//     // {
//     //     perror("Error\n");
//     //     return (FAILURE);
//     // }
//     map->width = 10;
//     map->height = 10;
//     return (SUCCESS);
// }

t_map	*map_init(t_vars *vars)
{
	t_map	*map;
    t_input *input;

	map = (t_map *) malloc(sizeof(t_map));
    if (map == NULL)
        return (NULL);
    vars->map = map;
    input = vars->input;
    map->structure = input->structure;
    // map->structure = malloc(sizeof(char *) * 6);
    // map->structure[0] = ft_strdup("111111");
    // map->structure[1] = ft_strdup("100101");
    // map->structure[2] = ft_strdup("101001");
    // map->structure[3] = ft_strdup("1100N1");
    // map->structure[4] = ft_strdup("111111");
    // map->structure[5] = NULL;
	map->width = input->width;
	map->height = input->height;
    // map_read_file(map, vars);
    // map_convert(map, vars);
	return (map);
}
