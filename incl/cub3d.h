/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:35:44 by hakobori          #+#    #+#             */
/*   Updated: 2024/11/20 04:57:16 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>   // printf, perror
# include <unistd.h>  // open, close, read, write
# include <stdlib.h>  // malloc, free, exit
# include <fcntl.h>   // open
# include <string.h>  // strerror
# include <sys/time.h> // gettimeofday
# include <math.h> // math functions
// # include <X11/X.h> // X11 keymap
# include "libft.h" // libft
# include "mlx.h" // mlx

# define WINDOW_TITLE "cub3d"
# define TILE_SIZE 32
# define BASE_SIZE 64
# define WINDOW_WIDTH 16
# define WINDOW_HEIGHT 9

# define VIEWING_ANGLE 60
# define FRAME_RATE 30
# define MOVE_SPEED 5
# define MOVE_DISTANCE 5
# define ROTATE_SPEED 5

# define PI 3.141592654

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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_input
{
	char	*no_line;
	char	*so_line;
	char	*we_line;
	char	*ea_line;
	char	*f_line;
	char    *c_line;
}	t_input;

typedef struct s_map {
	int		width;
	int		height;
	char	**structure;
}	t_map;

typedef struct s_texture
{
	int 	   	tile_size;
	t_image 	n;
	t_image 	s;
	t_image 	w;
	t_image 	e;
	int 	   	floor_argb;
	int 	   	ceil_argb;
}	t_texture;

typedef struct s_player
{
	t_vector    pos;
	double      dir;
	t_vector    vel;
	double      move_num;
}	t_player;

typedef struct s_vars
{
	char        *filename;
	// t_input     *input;
	void	    *mlx;
	int 	   	window_width;
	int 	   	window_height;
	void	    *window;
	t_image     *image;
	t_map	    *map;
	t_texture   *texture;
	t_player    *player;
}	t_vars;

//init
int		arg_check(int argc, char **argv);
int     map_read_file(t_map *map, t_vars *vars);
int     map_convert(t_map *map, t_vars *vars);
t_map	*map_init(t_vars *vars);
int     texture_init(t_vars *vars);
int     player_init(t_vars *vars);
t_vars	*vars_init(char **argv);

//mlx
void	exec_game(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		exit_game(t_vars *vars);

void    draw_background(t_vars *vars);
void    draw_wall(t_vars *vars);

void    my_mlx_pixel_put(t_image *image, int x, int y, int color);
int     load_image(t_image *image, char *filepath, t_vars *vars);

int     rgb_to_16argb(int r, int g, int b);

//control
void    rotate_player(t_vars *vars, double dir);
void	move_player(t_vars *vars, double dir);

double  deg_to_rad(double deg);
double  add_rad(double rad1, double rad2);

//util
void	free_array(char **array);


#endif
