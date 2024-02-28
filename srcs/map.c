/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:11:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
parse txt file and return a linked list of struct with a string as member.
*/
t_list	*fill_map_lst(t_fdf *fdf)
{
	int		fd;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	fd = open_file_or_exit(fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_new_line = 0;
			if (ft_strchr(line, '\n'))
				check_new_line = 1;
			str = ft_substr(line, 0, ft_strlen(line) - check_new_line);
			ft_lstadd_back(&input, ft_lstnew(str));
		}
		else
			break ;
		free(line);
	}
	close(fd);
	return (input);
}

void	fill_map(t_fdf *fdf)
{
	fdf->map->height = ft_lstsize(fdf->file_lst);
	fdf->map->width = get_width(fdf);
	fdf->map->matrix = init_matrix(fdf);
	fdf->map->size = 30;
	fdf->map->z_fact = 25;
	fill_matrix(fdf);
	get_x_offset(fdf);
	get_y_offset(fdf);
	update_size(fdf);
	update_matrix(fdf);
}

int	get_width(t_fdf *fdf)
{
	int		width;
	char	**coords;

	coords = ft_split(fdf->file_lst->content, ' ');
	is_malloc_or_exit(fdf, coords, "Memory allocation, fill_map()");
	width = check_size_strstr(coords);
	free_strstr(coords);
	return (width);
}

int	get_dist_btwn_cart_point(t_fdf *fdf)
{
	int	dist;
	int	height;
	int	width;

	height = fdf->map->height;
	width = fdf->map->width;
	dist = 30;
	while (((WIN_HEIGHT / 2) - ((height * dist) / 2))
		>= WIN_HEIGHT)
		dist--;
	while (((WIN_WIDTH / 2) - ((width * dist) / 2))
		>= WIN_WIDTH)
		dist--;
	return (dist);
}
