/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/19 18:14:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_master	*master;

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
		// ft_printf("x_max = %d\n", master->map->iso->x_max);
		// ft_printf("x_min = %d\n", master->map->iso->x_min);
		// ft_printf("x_offset = %d\n", master->map->iso->x_offset);
		// ft_printf("y_max = %d\n", master->map->iso->y_max);
		// ft_printf("y_min = %d\n", master->map->iso->y_min);
		// ft_printf("y_offset = %d\n", master->map->iso->y_offset);
		// ft_printf("y_max - y_min = %d\n", master->map->iso->y_max - master->map->iso->y_min);
		// ft_printf("WIN_HEIGHT / 2  - y_min = %d\n", (WIN_HEIGHT / 2) - master->map->iso->y_min);
		fdf_run(master);
		clean(master);
	}
	return (0);
}

void	initialization(t_master *master)
{
	master->file_lst = fill_map_lst(master);
	master->map = init_map(master);
}

void	fill_fdf(t_master *master)
{
	ft_strlcpy(master->proj, "ISO", 4);
	fill_map(master);
	master->mlx.mlx_ptr = mlx_init();
	master->mlx.win_ptr = mlx_new_window(master->mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, master->file_name);
}

void	fdf_run(t_master *master)
{
	draw_map(master);
	mlx_key_hook(master->mlx.win_ptr, &key_hook, master);
	mlx_hook(master->mlx.win_ptr, 17, 1L << 19, &close_mlx, master);
	mlx_loop(master->mlx.mlx_ptr);
}
