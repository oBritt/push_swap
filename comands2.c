/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:13:42 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:06:29 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **a, int i)
{
	t_list	*last;
	t_list	*first;

	if (!*a || !((*a)->next))
		return (1);
	first = *a;
	*a = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
	if (i)
		if (write(1, "ra\n", 3) == -1)
			return (0);
	return (1);
}

int	rb(t_list **b, int i)
{
	t_list	*last;
	t_list	*first;

	if (!*b || !((*b)->next))
		return (1);
	first = *b;
	*b = (*b)->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
	if (i)
		if (write(1, "rb\n", 3) == -1)
			return (0);
	return (1);
}

int	rr(t_list **a, t_list **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i)
		if (write(1, "rr\n", 3) == -1)
			return (0);
	return (1);
}
