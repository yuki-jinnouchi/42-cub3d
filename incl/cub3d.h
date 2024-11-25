/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:35:44 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/25 23:42:27 by hakobori         ###   ########.fr       */
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

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

//color
# define R 0
# define G 1
# define B 2


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
	char	*c;
	char	p;
	t_color	*f_detail;
	t_color	*c_detail;
	int		width;
	int		height;
	char	**structure;
}			t_map;

typedef	struct s_color {
	int r;
	int g;
	int b;
}	t_color;

#endif
