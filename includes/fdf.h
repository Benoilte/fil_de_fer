/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 14:44:21 by bebrandt         ###   ########.fr       */
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
	char	*color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		z_max;
	int		z_min;
	t_point	**matrix;
}	t_map;

typedef struct s_master
{
	char	*map_file;
	t_map	*map;
}	t_master;

// fdf.c

void			initialization(t_master *master);
void			fill_fdf(char *file, t_master *master);

// init_struct.c

t_master		*init_master(void);
t_map			*init_map(t_master *master);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(char *file);

// map.c

void			fill_map(t_master *master);
int				get_width(t_master *master);
int				get_height(t_master *master);

// matrix.c

t_point			**get_matrix(int height, int width);
void			fill_matrix(t_point **matrix, char *file, int h, int w);

// point.c


// safe_free.c

void			*free_strstr(char **array);
void			*free_empty_matrix(t_point **matrix, int size);

// cleanup.c

void			cleanup_and_exit(t_master *master, char *msg, int status);
void			cleanup_map(t_map *map);
void			cleanup_point(t_point *point);

#endif