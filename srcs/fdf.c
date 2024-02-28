/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/28 09:58:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

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
		fdf = init_fdf(argv[1]);
		initialization(fdf);
		check_file_empty(fdf);
		fill_fdf(fdf);
		fdf_run(fdf);
		clean(fdf);
	}
	return (0);
}

void	initialization(t_fdf *fdf)
{
	fdf->file_lst = fill_map_lst(fdf);
	fdf->camera = init_camera(fdf);
	fdf->map = init_map(fdf);
}

void	fill_fdf(t_fdf *fdf)
{
	fill_map(fdf);
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, fdf->file_name);
}

void	fdf_run(t_fdf *fdf)
{
	draw_map(fdf);
	mlx_key_hook(fdf->mlx.win_ptr, &key_hook, fdf);
	mlx_mouse_hook (fdf->mlx.win_ptr, &mouse_hook, fdf);
	mlx_hook(fdf->mlx.win_ptr, 17, 1L << 19, &close_mlx, fdf);
	mlx_loop(fdf->mlx.mlx_ptr);
}
