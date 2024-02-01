/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:26:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 11:22:08 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_strstr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

void	*free_empty_matrix(t_point **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	return (NULL);
}
