/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:35:44 by hakobori          #+#    #+#             */
/*   Updated: 2025/01/22 21:53:03 by hakobori         ###   ########.fr       */
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
# include "mlx_int.h" // mlx

// window settings
# define WINDOW_TITLE "cub3D"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define FOV 66
# define FRAME_RATE 30

// move settings
# define MOVE_DISTANCE 0.3
# define WALL_DISTANCE 0.2
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

# ifdef __linux__
#  include "keymap_linux.h"
# elif __APPLE__
#  include "keymap_mac.h"
# else
#  error "Unsupported operating system"
# endif

typedef struct s_dvec
{
	double	x;
	double	y;
}	t_dvec;

typedef struct s_ivec
{
	int	x;
	int	y;
}	t_ivec;

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
	int	x;
	int	y;
	int	player;
	int	len;
	int	up_len;
	int	down_len;
}	t_check_map;

typedef struct s_input {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	dir;
	t_dvec	position;
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
	t_dvec	pos;
	int		direction;
	double	plane_distance;
	double	ray_distance;
	int		wall_height;
	int		past_wall_height;
	int		window_start;
	int		window_end;
}	t_wall;

typedef struct s_texture
{
	t_image	*n;
	t_image	*s;
	t_image	*w;
	t_image	*e;
	int		floor_argb;
	int		ceil_argb;
}	t_texture;

typedef struct s_player
{
	t_dvec	pos;
	double	dir;
	t_dvec	dir_vec;
	double	fov_rad;
	t_dvec	plane;
	t_dvec	vel;
	int		move_num;
	int		rotate_num;
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
	int			*wall_heights;
	int			last_wall_x;
	int			last_wall_y;
	int			last_color;
	t_timeval	last_refresh;
	int			refresh_rate;
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
}	t_vars;

// ----------------init----------------
// init_vars.c
int		window_init(t_vars *vars);
t_vars	*vars_init(char **argv, t_input	*map_info);
// init_map.c
t_map	*map_init(t_vars *vars);
// init_texture.c
int		load_texture(t_image **image, char *filepath, t_vars *vars);
int		texture_init(t_vars *vars);
// init_player.c
double	get_dir(t_vars *vars);
int		player_init(t_vars *vars);
// init_image.c
int		image_init(t_vars *vars);

// ----------------arg_check----------------
// arg_check.c
int		arg_check(int argc, char **argv);
// error.c
void	print_error_msg_free(t_input *map_info, char *line, char *error_msg);
void	print_error_msg(char *error_msg);
void	perror_free_map_info(t_input *map_info, char *error_msg);
// ----------------parser----------------
// parser.c
int		parser(char *file, t_input *map_info);
int		set_textures_and_colors(char *line, int fd, t_input *map_info);
int		open_file(char *file, int *fd);
// check_color.c
int		set_int_color(int type, char *color, t_color *color_detail);
int		set_color_detail(char **split_color_info, t_color *color_detail);
int		check_color_valid(char *color_info, t_input *map_info, int type);
int		check_color_valid_fc(t_input *map_info, void *mlx);
// check_img_path_and_color.c
int		count_values(int type);
int		check_img_path_and_color(t_input *map_info);
int		set_path_color_info( \
	int type, t_input *map_info, char *line, int *count_info);
int		type_identifier( \
	char *line, int len, t_input *map_info, int *count_info);
//check_img_path.c
int		check_img_path_exist(char *img_path, void *mlx);
int		check_img_path_exist_all(t_input *map_info, void *mlx);
//check_map_utils.c
int		skip_newline(char **line, int fd, t_input *map_info);
//check_map.c
int		find_player(t_input *map_info, int *player, int i, int j);
int		check_map(t_input *map_info);
//check_map_is_space.c
int		ft_isspace(int c);
int		relative_position_is_space(t_input *map_info, t_check_map *cmap);
//get_map.c
int		get_map(t_input *map_info, int fd, char *line);
//find_player.c
int		find_player(t_input *map_info, int *player, int i, int j);

// ----------------control----------------
// exec_game.c
void	exec_game(t_vars *vars);
// key_hooks.c
int		key_hook(int keycode, t_vars *vars);
// move_player.c
void	move_player(t_vars *vars, double dir);
int		check_player_move(t_dvec *t_pos, double move_dir, int i, t_vars *vars);
t_dvec	get_next_move_pos(t_player player, double move_dir, t_vars *vars);
// rotate_player.c
void	rotate_player(t_vars *vars, double dir);
// exit_game.c
int		exit_game(t_vars *vars);

// ----------------draw----------------
// draw_bg.c
void	draw_floor(int window_x, int new_height, int past_height, t_vars *vars);
void	draw_ceil(int window_x, int new_height, int past_height, t_vars *vars);
void	draw_init_background(t_vars *vars);
void	memcpy_bg_image(t_vars *vars);
// draw_refresh_img.c
void	draw_wall(t_wall *wall, int window_x, t_vars *vars);
void	draw_line_wrapper(int window_x, t_vars *vars);
void	draw_refresh_img(t_vars *vars);
// draw_refresh_img.c
void	draw_refresh_img(t_vars *vars);
// refresh_screen.c
int		refresh_screen(t_vars *vars);
// util_color.c
int		to_uint_rgb(int r, int g, int b);
int		get_image_color(t_image *image, int x, int y);
int		get_image_color_by_ratio( \
	t_image *image, double x_ratio, double y_ratio, t_vars *vars);
int		get_texture_color( \
	t_wall *wall, double window_y_ratio, t_vars *vars);
// util_mlx.c
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

// ----------------ray_calc----------------
// calc_raycast.c
t_dvec	calc_raycast(t_player *player, int window_width, int i);
//calc_next_pos.c
t_dvec	next_pos_flat(t_dvec pos, t_dvec ray);
t_dvec	next_pos_steep(t_dvec pos, t_dvec ray);
t_dvec	next_pos(t_dvec pos, t_dvec ray);
// calc_wall.c
t_wall	calc_wall_position(t_dvec ray, t_dvec position, t_vars *vars);
t_wall	calc_wall(t_player *player, int window_x, t_vars *vars);
// calc_distance.c
double	calc_ray_distance(t_dvec wall_pos, t_dvec player_pos);
double	calc_plane_distance(t_dvec wall_pos, t_player *player);
// util_vector.c
int		update_plane(t_player *player);
int		is_cross_line(double v_current, double v_last);
double	next_grid_v(double v_pos, double v_ray);
int		check_wall_num(t_dvec current_pos, t_dvec ray, char **structure);

// ----------------utils----------------
// util_abs.c
double	abs_double(double num);
// util_degrees.c
double	deg_to_rad(double deg);
double	round_rad(double rad);
double	add_rad(double rad1, double rad2);
t_dvec	dir_to_vec(double dir);
// util_time.c
int		is_screen_renew(t_timeval *current, t_timeval *last);
// util_free.c
void	free_if_exist(void *ptr);
void	free_array(char **array);
size_t	ft_strlen_null_gard(const char *s);
// free_map_info.c
void	free_map_info(t_input *map_info);
void	free_map_info_after_init(t_input *map_info);
void	free_map_info_map_structure(t_input *map_info);
// free_texture.c
void	free_texture(t_image *texture, t_vars *vars);
void	free_all_texture(t_texture *texture, t_vars *vars);
//is_space.c
int		ft_isspace(int c);
#endif
