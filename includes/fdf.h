/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/27 22:54:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# include "../libft/includes/libft.h"
# include "color.h"

# ifdef MACOS
#  include "../mlx_macos/mlx.h"
#  include "key_macos.h"
# elif LINUX
#  include "key_linux.h"
#  include "../mlx_linux/mlx.h"
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH		1440
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT	900
# endif

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		x_proj;
	int		y_proj;
	int		z_proj;
	int		color;
}	t_point;

typedef struct s_bres
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	ex;
	double	ex_abs;
	double	ey;
	double	ey_abs;
	double	dx;
	double	dy;
	double	x_rise;
	double	y_rise;
	double	i;
}	t_bres;

typedef struct s_color
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	g1;
	unsigned char	g2;
	unsigned char	b1;
	unsigned char	b2;
}	t_color;

typedef struct s_map
{
	int		height;
	int		width;
	int		x_max;
	int		x_min;
	int		y_max;
	int		y_min;
	int		z_max;
	int		z_min;
	int		z_fact;
	int		x_offset;
	int		y_offset;
	int		size;
	int		color_is_set;
	double	zoom;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	t_point	***matrix;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct s_master
{
	char	*file_name;
	t_list	*file_lst;
	t_map	*map;
	char	proj[5];
	t_vars	mlx;
	t_data	img;
}	t_master;

// fdf.c

void			initialization(t_master *master);
void			fill_fdf(t_master *master);
void			fdf_run(t_master *master);

// init_struct.c

t_master		*init_master(char *file);
t_map			*init_map(t_master *master);
t_point			*init_point(t_master *master);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(t_master *master);
int				check_size_strstr(char **strstr);

// map.c

t_list			*fill_map_lst(t_master *master);
void			fill_map(t_master *master);
int				get_width(t_master *master);
int				get_dist_btwn_cart_point(t_master *master);

// map_utils.c

void			get_x_offset(t_master *master);
void			get_y_offset(t_master *master);
void			update_size(t_master *master);
void			update_map(t_master *master);
void			replace_map(t_master *master);

// matrix.c

t_point			***init_matrix(t_master *master);
void			init_width_matrix(t_master *master, t_point **matrix);
void			fill_matrix(t_master *master);
void			update_matrix(t_master *master);
void			get_min_max(t_master *master, t_point *point);

// point.c

void			fill_point(t_master *master, int x, int y, char *val);
void			update_point(t_master *master, int x, int y);
void			iso(t_point *point);

// event.c

int				key_hook(int key, t_master *master);
int				key_hook_next(int key, t_master *master);
int				mouse_hook(int button, int x, int y, t_master *master);
int				close_mlx(t_master *master);

// draw.c

void			draw_map(t_master *master);
void			draw_lines(t_master *master, int x, int y);
void			ft_bresenham(t_master *master, t_point *current, t_point *next);
void			slope_first_case(t_data img, t_bres val, int col1, int col2);
void			slope_second_case(t_data img, t_bres val, int col1, int col2);

// color.h

int				get_color(int color1, int color2, float fraction);
double			get_perc(double start, double end, double size);

// transform.c

void			zoom(double zoom, t_master *master);
void			reset_map(t_master *master);

// rotate.c

void			rotate(t_master *master, char axis, double angle);
void			rotate_x(t_master *master, int x, int y);
void			rotate_y(t_master *master, int x, int y);
void			rotate_z(t_master *master, int x, int y);

// mlx_utils.c

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

// safe_free.c

void			*free_strstr(char **array);
void			del(void *content);

// check_malloc.c

void			is_malloc_or_exit(t_master *master, void *ptr, char *msg);
int				open_file_or_exit(t_master *master);

// cleanup.c

void			clean_and_exit(t_master *master, char *msg, int status);
void			clean(t_master *master);
void			clean_map(t_map *map);
void			clean_matrix(t_point ***matrix);
void			clean_point(t_point *point);

// test_function.c

void			ft_print_matrix(t_point ***matrix);
void			display_struct(t_list *lst);

#endif
