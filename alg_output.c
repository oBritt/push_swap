/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:39:09 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:07:34 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra rb rra rrb rr rrr

int	outputting(t_list **a, t_list **b, int *out)
{
	while (out[0]--)
		if (!ra(a, 1))
			return (0);
	while (out[1]--)
		if (!rb(b, 1))
			return (0);
	while (out[2]--)
		if (!rra(a, 1))
			return (0);
	while (out[3]--)
		if (!rrb(b, 1))
			return (0);
	while (out[4]--)
		if (!rr(a, b, 1))
			return (0);
	while (out[5]--)
		if (!rrr(a, b, 1))
			return (0);
	return (1);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
