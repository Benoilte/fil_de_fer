/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/01 13:31:16 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <limits.h>

# include "../libft/includes/libft.h"
# include "color.h"

# ifdef MACOS
#  include "../mlx_macos/mlx.h"
#  include "key_macos.h"
# elif LINUX
#  include "key_linux.h"
#  include "../mlx_linux/mlx.h"
# endif

# ifndef WIN_W
#  define WIN_W		1440
# endif

# ifndef MENU_W
#  define MENU_W	300
# endif

# ifndef WIN_H
#  define WIN_H		900
# endif

enum
{
	ISO,
	PARALLEL
};

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
	int		color_1;
	int		color_2;
	int		color_is_set;
	t_point	***matrix;
}	t_map;

typedef struct s_camera
{
	int		projection;
	double	zoom;
	int		size;
	int		z_fact;
	int		x_offset;
	int		y_offset;
	double	rot_x;
	double	rot_y;
	double	rot_z;
}	t_camera;

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

typedef struct s_fdf
{
	char		*file_name;
	t_list		*file_lst;
	t_map		*map;
	t_camera	*camera;
	t_vars		mlx;
	t_data		img;
}	t_fdf;

// fdf.c

void			initialization(t_fdf *fdf);
void			fill_fdf(t_fdf *fdf);
void			fdf_run(t_fdf *fdf);

// init_struct.c

t_fdf			*init_fdf(char *file);
t_camera		*init_camera(t_fdf *fdf);
t_map			*init_map(t_fdf *fdf);
t_point			*init_point(t_fdf *fdf);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(t_fdf *fdf);
int				check_size_strstr(char **strstr);

// map.c

t_list			*fill_map_lst(t_fdf *fdf);
void			fill_map(t_fdf *fdf);
int				get_width(t_fdf *fdf);
void			print_menu(t_fdf *fdf);

// map_utils.c

void			get_x_offset(t_fdf *fdf);
void			get_y_offset(t_fdf *fdf);
void			update_size(t_fdf *fdf);
void			update_map(t_fdf *fdf);
void			replace_map(t_fdf *fdf);

// matrix.c

t_point			***init_matrix(t_fdf *fdf);
void			init_width_matrix(t_fdf *fdf, t_point **matrix);
void			fill_matrix(t_fdf *fdf);
void			update_matrix(t_fdf *fdf);
void			get_min_max(t_fdf *fdf, t_point *point);

// point.c

void			fill_point(t_fdf *fdf, int x, int y, char *val);
void			update_point(t_fdf *fdf, int x, int y);
void			set_projection(t_fdf *fdf, t_point *point);

// event.c

int				key_hook(int key, t_fdf *fdf);
int				key_hook_next(int key, t_fdf *fdf);
int				mouse_hook(int button, int x, int y, t_fdf *fdf);
int				resize_mlx(t_fdf *fdf);
int				close_mlx(t_fdf *fdf);

// draw.c

void			draw_map(t_fdf *fdf);
void			draw_lines(t_fdf *fdf, int x, int y);
void			ft_bresenham(t_fdf *fdf, t_point *current, t_point *next);
void			slope_first_case(t_data img, t_bres val, int col1, int col2);
void			slope_second_case(t_data img, t_bres val, int col1, int col2);

// color.h

int				get_color(int color1, int color2, float fraction);
double			get_perc(double start, double end, double size);

// transform.c

void			zoom(double zoom, t_fdf *fdf);
void			change_color(t_fdf *fdf);
void			reset_map(t_fdf *fdf);

// rotate.c

void			rotate(t_fdf *fdf, char axis, double angle);
void			rotate_x(t_fdf *fdf, int x, int y);
void			rotate_y(t_fdf *fdf, int x, int y);
void			rotate_z(t_fdf *fdf, int x, int y);
void			view(int key, t_fdf *fdf);

// mlx_utils.c

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

// safe_free.c

void			*free_strstr(char **array);
void			del(void *content);

// check_malloc.c

void			is_malloc_or_exit(t_fdf *fdf, void *ptr, char *msg);
int				open_file_or_exit(t_fdf *fdf);

// cleanup.c

void			clean_and_exit(t_fdf *fdf, char *msg, int status);
void			clean(t_fdf *fdf);
void			clean_map(t_map *map);
void			clean_matrix(t_point ***matrix);
void			clean_point(t_point *point);

// test_function.c

void			ft_print_matrix(t_point ***matrix);
void			display_struct(t_list *lst);

#endif
