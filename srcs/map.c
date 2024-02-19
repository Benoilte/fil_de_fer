/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 11:49:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
parse txt file and return a linked list of struct with a string as member.
*/
t_list	*fill_map_lst(t_master *master)
{
	int		fd;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	fd = open_file_or_exit(master);
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

void	fill_map(t_master *master)
{
	int	point_dist;

	master->map->height = ft_lstsize(master->file_lst);
	master->map->width = get_width(master);
	master->map->matrix = init_matrix(master);
	master->map->point_dist = get_dist_btwn_iso_point(master);
	point_dist = master->map->point_dist;
	master->map->iso_height_offset = (WIN_HEIGHT / 2)
		- ((((master->map->width * point_dist) * sin(120))
				+ ((master->map->height * point_dist) * sin(120 + 2))) / 2);
	master->map->iso_width_offset = (WIN_WIDTH / 2);
	fill_matrix(master);
}

int	get_width(t_master *master)
{
	int		width;
	char	**coords;

	coords = ft_split(master->file_lst->content, ' ');
	is_malloc_or_exit(master, coords, "Memory allocation, fill_map()");
	width = check_size_strstr(coords);
	free_strstr(coords);
	return (width);
}

int	get_dist_btwn_cart_point(t_master *master)
{
	int	dist;
	int	height;
	int	width;

	height = master->map->height;
	width = master->map->width;
	dist = 20;
	while (((WIN_HEIGHT / 2) - ((height * dist) / 2))
		>= WIN_HEIGHT)
		dist--;
	while (((WIN_WIDTH / 2) - ((width * dist) / 2))
		>= WIN_WIDTH)
		dist--;
	return (dist);
}

int	get_dist_btwn_iso_point(t_master *master)
{
	int	d;
	int	h;
	int	w;
	int	z;

	h = master->map->height;
	w = master->map->width;
	z = ((master->map->matrix)[h -1][w - 1])->z;
	d = 20;
	while ((y_cart_to_iso(w * d, h * d, z * d)
			+ (((WIN_HEIGHT - y_cart_to_iso(w * d, h * d, z * d)) / 2))
			>= WIN_HEIGHT) && d > 1)
		d--;
	z = ((master->map->matrix)[0][w - 1])->z;
	while (((x_cart_to_iso(0, w * d, z * d)) + (WIN_WIDTH / 2)
			>= WIN_WIDTH) && d > 1)
		d--;
	return (d);
}
