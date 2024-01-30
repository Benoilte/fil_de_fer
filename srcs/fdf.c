/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:39:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 18:36:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error: .fdf file format is missing\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Error: too many argument is given\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		check_input(argv[1]);
		ft_printf("file format is correct\n");
	}
	return (0);
}
