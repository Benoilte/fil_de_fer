/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/05 18:19:28 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# include "../libft/includes/libft.h"

# ifdef MACOS
#  include "../mlx_macos/mlx.h"
#  include "key_macos.h"
# elif LINUX
#  include "key_linux.h"
#  include "../mlx_linux/mlx.h"
# endif

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

typedef struct s_point
{
	int		z;
	char	color[10];
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		z_max;
	int		z_min;
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
	t_vars	*mlx;
	t_data	*data_img;
}	t_master;

// fdf.c

void			initialization(t_master *master);
void			fill_fdf(t_master *master);
int				close_mlx(t_master *master);
void			fdf_run(t_master *master);

// init_struct.c

t_master		*init_master(char *file);
t_map			*init_map(t_master *master);
t_point			*init_point(t_master *master);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(t_master *master);

// map.c

t_list			*fill_map_lst(t_master *master);
void			fill_map(t_master *master);
int				get_width(t_master *master);

// matrix.c

t_point			***init_matrix(t_master *master);
void			init_width_matrix(t_master *master, t_point **matrix);
void			fill_matrix(t_master *master);

// point.c

void			fill_point(t_master *master, t_point *point, char *val);

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
