/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:35:44 by hakobori          #+#    #+#             */
/*   Updated: 2024/12/19 02:01:47 by retanaka         ###   ########.fr       */
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
# include <stdint.h>
// # include <X11/X.h> // X11 keymap
# include "libft.h" // libft
# include "mlx.h" // mlx

# define WINDOW_TITLE "cub3D"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define FOV 66

# define FRAME_RATE 30
# define MOVE_SPEED 0.05
# define MOVE_DISTANCE 1
# define ROTATE_SPEED 10

# define PI 3.141592654

# define NEXT 2
# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILURE -1

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

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

# define ABS(x) ((x) < 0 ? -(x) : (x))
// # define SIGN(x) ((x) < 0 ? -1 : 1)

# ifdef __linux__
#  include "keymap_linux.h"
# elif __APPLE__
#  include "keymap_mac.h"
# else
#  error "Unsupported operating system"
# endif

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct timeval	t_timeval;

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

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_check_map{
	int	i;
	int	j;
	int	player;
	int	len;
	int	up_len;
	int	down_len;
} t_check_map;

typedef struct s_input {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	dir;
	t_vec	position;
	t_color	f_detail;
	t_color	c_detail;
	int		width;
	int		height;
	char	**structure;
}			t_input;

typedef struct s_map {
	int		width;
	int		height;
	char	**structure;
}	t_map;

typedef struct s_wall
{
	t_vec	pos;
	int		direction;
	double	distance;
	double	length;
}	t_wall;

typedef struct s_texture
{
	t_image	n;
	t_image	s;
	t_image	w;
	t_image	e;
	int		floor_argb;
	int		ceil_argb;
}	t_texture;

typedef struct s_player
{
	t_vec	pos;
	double	dir;
	t_vec	dir_vec;
	double	fov_rad;
	t_vec	plane;
	t_vec	vel;
	double	move_num;
}	t_player;

typedef struct s_vars
{
	char		*filename;
	t_input		*input;
	void		*mlx;
	int			window_width;
	int			window_height;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_texture	*texture;
	t_player	player;
	t_vec		ray;
	t_wall		wall;
}	t_vars;

//init
// init_vars.c
int		window_init(t_vars *vars);
int		image_init(t_vars *vars);
int		set_vars(t_vars	*vars, t_input *map_info);
int		vars_init(char **argv, t_input	*map_info, t_vars *vars);
// init_map.c
t_map	*map_init(t_vars *vars);
// init_texture.c
int		load_texture(t_image *image, char *filepath, t_vars *vars);
int		texture_init(t_vars *vars);
// init_player.c
double	get_dir(t_vars *vars);
void	player_init(t_vars *vars);
int		map_read_file(t_map *map, t_vars *vars);
int		map_convert(t_map *map, t_vars *vars);

//arg_check
// arg_check.c
int		arg_check(int argc, char **argv);
// error.c
void	print_error_msg_free(t_input *map_info, char *line, char *error_msg);
void	print_error_msg(char *error_msg);
void	print_error_msg_free_map_info(t_input *map_info, char *error_msg);

//parser
// parser.c
int		parser(char *file, t_input *map_info);
int		set_textures_and_colors(char *line, int fd, t_input *map_info);
int		open_file(char *file, int *fd);
// check_color.c
int		set_int_color(int type, char *color, t_color *color_detail);
int		set_color_detail(char **split_color_info, t_color *color_detail);
int		check_color_valid(char *color_info, t_input *map_info, int type);
// check_img_path_and_color.c
int		count_values(int type);
int		check_img_path_and_color(t_input *map_info);
int		set_path_color_info( \
	int type, t_input *map_info, char *line, int *count_info);
int		type_identifier( \
	char *line, int len, t_input *map_info, int *count_info);
//check_img_path.c
int		check_img_path_exist(char *img_path, void *mlx);
//check_map_utils.c
int		skip_newline(char **line, int fd, t_input *map_info);
//check_map.c
int		find_player(t_input *map_info, int *player, int i, int j);
int		check_map(t_input *map_info);
//get_map.c
int		get_map(t_input *map_info, int fd, char *line);
//find_player.c
int	find_player(t_input *map_info, int *player, int i, int j);

//control
// exec_game.c
void	exec_game(t_vars *vars);
// key_hooks.c
int		key_hook(int keycode, t_vars *vars);
// move_player.c
void	rotate_player(t_vars *vars, double dir);
void	move_player(t_vars *vars, double dir);
// exit_game.c
int		exit_game(t_vars *vars);
// util_degrees.c
double	deg_to_rad(double deg);
double	round_rad(double rad);
double	add_rad(double rad1, double rad2);
t_vec	dir_to_vec(double dir);

//mlx
// draw_bg.c
void	draw_background(t_vars *vars);
// draw_wall.c
uint32_t	get_texture_color( \
	t_wall wall, double y_window_ratio, t_vars vars);
void	draw_wall_line3(t_wall wall, int x_window, t_vars *vars);
void	draw_wall_line2(int x_window, t_vars *vars);
void	draw_wall(t_vars *vars);
// draw_screen.c
void	draw_screen(t_vars *vars);
// util_color.c
uint32_t	to_uint_rgb(int r, int g, int b);
uint32_t	get_image_color(t_image image, int x, int y);
uint32_t	get_image_color_by_ratio( \
	t_image image, double x_ratio, double y_ratio);
// util_mlx.c
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

//ray_calc
// calc_ray.c
t_vec	get_next_pos_flat(t_vec pos, t_vec ray, double slope_y);
t_vec	get_next_pos_steep(t_vec pos, t_vec ray, double slope_x);
t_vec	calc_ray(t_player *player, int window_width, int i);
// calc_wall.c
int		check_wall_num(t_vec current_pos, t_vec ray, char **structure);
t_wall	calc_wall_flat(t_vec *ray, t_player *player, t_vars *vars);
t_wall	calc_wall_steep(t_vec *ray, t_player *player, t_vars *vars);
t_wall	calc_wall_pos(t_vec *ray, t_player *player, t_vars *vars);
// calc_distance.c
double	calc_player_distance(t_vec wall_pos, t_vec player_pos);
double	calc_plane_distance(t_vec wall_pos, t_player *player);
// util_vector.c
int		update_plane(t_player *player);
int		check_cross_line(double current, double last);
double	jump_next_pos(double pos, double ray);

//utils
// free.c
void	free_color(t_color *color);
void	free_map_info(t_input *map_info);
size_t	ft_strlen_null_gard(const char *s);
void	free_map_info_after_init(t_input *map_info);
// util_time.c
int		is_screen_renew(t_timeval current, t_timeval last);
// util.c
void	free_array(char **array);

#endif
