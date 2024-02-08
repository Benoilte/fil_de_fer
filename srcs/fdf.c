/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/08 15:40:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_master	*master;
	// int			n1;
	// int			n2;
	// int			n3;
	// int			n4;

	if (argc < 2)
	{
		ft_printf("Error: File is missing\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Error: Too many argument\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		check_file_name(argv[1]);
		check_file_exist(argv[1]);
		master = init_master(argv[1]);
		initialization(master);
		check_file_empty(master);
		fill_fdf(master);
		// ft_printf("point_dist: %d\n", master->map->point_dist);
		// ft_printf("height: %d\n", master->map->height);
		// ft_printf("width: %d\n", master->map->width);
		fdf_run(master);
		// ft_print_matrix(master->map->matrix);
		// n1 = 2;
		// n2 = 1;
		// n3 = 4;
		// n4 = 3;
		// ft_printf("n1 : %d\n", n1);
		// ft_printf("n2 : %d\n", n2);
		// ft_printf("n3 : %d\n", n3);
		// ft_printf("n4 : %d\n", n4);
		// ft_printf("ptr n4 : %p\n", &n4);
		// ft_printf("---------------\n");
		// draw_line(n1, n2, n3, n4);
		// ft_printf("---------------\n");
		// ft_printf("n1 : %d\n", n1);
		// ft_printf("n2 : %d\n", n2);
		// ft_printf("n3 : %d\n", n3);
		// ft_printf("n4 : %d\n", n4);
		clean(master);
	}
	return (0);
}

void	initialization(t_master *master)
{
	master->file_lst = fill_map_lst(master);
	display_struct(master->file_lst);
	master->map = init_map(master);
}

void	fill_fdf(t_master *master)
{
	t_vars	*mlx;

	master->win_width = 1920;
	master->win_height = 1080;
	ft_strlcpy(master->proj, "ISO", 4);
	fill_map(master);
	mlx = (t_vars *)malloc(sizeof(t_vars));
	is_malloc_or_exit(master, mlx, "Memory allocation, fill_fdf()");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			master->file_name);
	master->mlx = mlx;
}

void	fdf_run(t_master *master)
{
	draw_map(master);
	mlx_key_hook(master->mlx->win_ptr, &key_hook, master);
	mlx_hook(master->mlx->win_ptr, 17, 1L << 19, &close_mlx, master);
	mlx_loop(master->mlx->mlx_ptr);
}
