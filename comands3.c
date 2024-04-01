/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:16:18 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:05:29 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list	**a, int i)
{
	t_list	*last;
	t_list	*prev;

	if (!*a || !((*a)->next))
		return (1);
	prev = *a;
	last = prev->next;
	while (last->next)
	{
		last = last->next;
		prev = prev->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (i)
		if (write(1, "rra\n", 4) == -1)
			return (0);
	return (1);
}

int	rrb(t_list **b, int i)
{
	t_list	*last;
	t_list	*prev;

	if (!*b || !((*b)->next))
		return (1);
	prev = *b;
	last = prev->next;
	while (last->next)
	{
		last = last->next;
		prev = prev->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (i)
		if (write(1, "rrb\n", 4) == -1)
			return (0);
	return (1);
}

int	rrr(t_list **a, t_list **b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	if (i)
		if (write(1, "rrr\n", 4) == -1)
			return (0);
	return (1);
}
