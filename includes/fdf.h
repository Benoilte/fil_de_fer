/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:43:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 22:37:35 by bebrandt         ###   ########.fr       */
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

typedef struct s_origin_map
{
	int	height;
	int	width;
	int	z_max;
	int	z_min;
	int	**matrix;
}	t_origin_map;

// fdf.c

void			fdf_init(char *file);

// input_validation.c

void			check_file_name(char *file);
void			check_file_exist(char *file);
void			check_file_empty(char *file);

// map.c

t_origin_map	*new_map(char *file);
int				get_width(char *file);
int				get_height(char *file);

// safe_free.c

void	free_strstr(char **array);

#endif