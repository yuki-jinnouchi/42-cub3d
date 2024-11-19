/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:35:44 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/19 22:57:42 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_TITLE "cub3D"

# define TILE_SIZE 32
# define WINDOW_WIDTH 16
# define WINDOW_HEIGHT 9

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILURE -1

# ifdef __linux__
#  include "keymap_linux.h"
# elif __APPLE__
#  include "keymap_mac.h"
# else
#  error "Unsupported operating system"
# endif

# include <stdio.h>   // printf, perror
# include <unistd.h>  // open, close, read, write
# include <stdlib.h>  // malloc, free, exit
# include <fcntl.h>   // open
# include <string.h>  // strerror
# include <sys/time.h> // gettimeofday
# include "libft.h" // libft
# include "mlx.h" // mlx

typedef struct s_map {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	int		width;
	int		height;
	char	**structure;
}			t_map;

#endif
