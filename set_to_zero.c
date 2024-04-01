/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:05:54 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 16:43:40 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	set_to_zero(int	*array)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 1000)
// 	{
// 		array[i] = 0;
// 		i++;
// 	}
// }

void	set_to_max(int *array, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		array[i] = 2147483647;
		i++;
	}
}

void	set_to_zero_ind(int *array, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		array[i] = 0;
		i++;
	}
}
