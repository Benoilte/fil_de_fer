/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:47:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/30 18:16:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_input(char *file)
{
	check_file_name(file);
}

void	check_file_name(char *file)
{
	char	*format;

	format = ft_strrchr(file, '.');
	if (format == NULL || ft_strncmp(format, ".fdf", 5))
	{
		ft_printf("file format is not correct\n");
		exit(0);
	}
}
