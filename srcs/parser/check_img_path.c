/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/24 00:22:41 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_img_path_exist(char *img_path)
{
    void *mlx;
    void *img;
    int width;
    int height;
    
    mlx = mlx_init();
    if (!mlx)
        return (FALSE);
    width = 42;
    height = 42;
    img = mlx_xpm_file_to_image(mlx, img_path, &width, &height);
    if (!img)
        return (mlx_destroy_display(mlx), FALSE);
    return (mlx_destroy_display(mlx), TRUE);
}
