/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:57:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/03 21:46:42 by hakobori         ###   ########.fr       */
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
		return (mlx_destroy_display(mlx), free(mlx), FALSE);
	return (mlx_destroy_image(mlx, img), TRUE);
}
