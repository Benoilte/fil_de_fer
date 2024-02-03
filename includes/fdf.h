/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/03 14:27:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# include "../libft/includes/libft.h"

# ifdef MACOS
#  include "key_macos.h"
# elif LINUX
#  include "key_linux.h"
# endif

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

typedef struct s_master
{
	t_list	*map_file;
	t_map	*map;
}	t_master;

// fdf.c

void			initialization(t_master *master);
void			fill_fdf(t_list *map_lst, t_master *master);

// init_struct.c

t_master		*init_master(void);
t_map			*init_map(t_master *master);
t_point			*init_point(t_master *master);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(t_list *map_lst);

// map.c

t_list			*fill_map_lst(char *file);
void			fill_map(t_master *master);
int				get_width(t_master *master);
int				get_height(t_master *master);

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

// cleanup.c

void			cleanup_and_exit(t_master *master, char *msg, int status);
void			cleanup_map(t_map *map);
void			cleanup_matrix(t_point ***matrix);
void			cleanup_point(t_point *point);

// test_function.c

void			ft_print_matrix(t_point ***matrix);
void			display_struct(t_list *lst);

#endif
