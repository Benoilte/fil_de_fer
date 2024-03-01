/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/01 13:28:26 by bebrandt         ###   ########.fr       */
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
	fdf->camera->size = 30;
	fdf->camera->z_fact = 25;
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

void	print_menu(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 15, 50, WHITE, "Command Macos (Linux)");
	mlx_string_put(mlx, win, 15, 100, WHITE, "Move: Arrows");
	mlx_string_put(mlx, win, 15, 130, WHITE, "Zoom: scroll or (Pgup/Pgdn)");
	mlx_string_put(mlx, win, 15, 160, WHITE, "Flatten: +/-");
	mlx_string_put(mlx, win, 15, 190, WHITE, "Rotatation:");
	mlx_string_put(mlx, win, 45, 220, WHITE, "X-Axis: W / S");
	mlx_string_put(mlx, win, 45, 250, WHITE, "Y-Axis: A / D");
	mlx_string_put(mlx, win, 45, 280, WHITE, "Z-Axis: X / Z (Y)");
	mlx_string_put(mlx, win, 15, 310, WHITE, "Projection :");
	mlx_string_put(mlx, win, 45, 340, WHITE, "ISO : I");
	mlx_string_put(mlx, win, 45, 370, WHITE, "Parallel : P");
	mlx_string_put(mlx, win, 15, 400, WHITE, "View in parallel:");
	mlx_string_put(mlx, win, 45, 430, WHITE, "Top : 1");
	mlx_string_put(mlx, win, 45, 460, WHITE, "Bottom : 2");
	mlx_string_put(mlx, win, 45, 490, WHITE, "Left : 3");
	mlx_string_put(mlx, win, 45, 520, WHITE, "Right : 4");
	mlx_string_put(mlx, win, 45, 550, WHITE, "Front : 5");
	mlx_string_put(mlx, win, 45, 580, WHITE, "Back : 6");
	mlx_string_put(mlx, win, 15, 610, WHITE, "Change color : tab");
	mlx_string_put(mlx, win, 15, 640, WHITE, "Reset : R");
}
