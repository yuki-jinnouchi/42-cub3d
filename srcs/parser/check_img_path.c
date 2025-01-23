/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/21 21:57:50 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_img_path_exist(char *img_path, void *mlx)
{
	void	*img;
	int		width;
	int		height;

	if (!mlx)
		return (FALSE);
	img = NULL;
	img = mlx_xpm_file_to_image(mlx, img_path, &width, &height);
	if (!img)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (FALSE);
	}
	return (mlx_destroy_image(mlx, img), TRUE);
}

int	check_img_path_exist_all(t_input *map_info, void *mlx)
{
	if (check_img_path_exist(map_info->no, mlx) == FALSE)
	{
		print_error_msg("NO invalid path\n");
		return (FALSE);
	}
	if (check_img_path_exist(map_info->so, mlx) == FALSE)
	{
		print_error_msg("SO invalid path\n");
		return (FALSE);
	}
	if (check_img_path_exist(map_info->we, mlx) == FALSE)
	{
		print_error_msg("WE invalid path\n");
		return (FALSE);
	}
	if (check_img_path_exist(map_info->ea, mlx) == FALSE)
	{
		print_error_msg("EA invalid path\n");
		return (FALSE);
	}
	return (TRUE);
}
