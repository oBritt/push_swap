/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:45:12 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:07:17 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a, int i)
{
	t_list	*first;
	t_list	*second;
	int		ans;

	ans = 1;
	if (!*a || !((*a)->next))
		ans = 0;
	if (ans)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if (i)
		if (write(1, "sa\n", 3) == -1)
			return (0);
	return (1);
}

int	sb(t_list **a, int i)
{
	t_list	*first;
	t_list	*second;
	int		ans;

	ans = 1;
	if (!*a || !((*a)->next))
		ans = 0;
	if (ans)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if (i)
		if (write(1, "sb\n", 3) == -1)
			return (0);
	return (1);
}

int	ss(t_list **a, t_list **b, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i)
		if (write(1, "ss\n", 3) == -1)
			return (0);
	return (1);
}

int	pa(t_list **a, t_list **b, int i)
{
	t_list	*t;

	t = *b;
	*b = (*b)->next;
	t->next = *a;
	*a = t;
	if (i)
		if (write(1, "pa\n", 3) == -1)
			return (0);
	return (1);
}

int	pb(t_list **a, t_list **b, int i)
{
	t_list	*t;

	t = *a;
	*a = (*a)->next;
	t->next = *b;
	*b = t;
	if (i)
		if (write(1, "pb\n", 3) == -1)
			return (0);
	return (1);
}
