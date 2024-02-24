/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:05:24 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 16:55:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_matrix(t_point ***matrix)
{
	int	y;
	int	x;

	y = 0;
	ft_printf("\n------ This is the Matrix --------\n\n");
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			ft_printf("%2d ", ((matrix[y][x])->z));
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	display_struct(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
