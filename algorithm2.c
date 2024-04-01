/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:16:14 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:08:33 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_solving(t_list **a, t_list **b)
{
	int	t;

	t = check_if_sorted_alg(a);
	if (t == -1)
		return (0);
	if (!check_if_sorted_alg(a))
		if (!sa(a, 1))
			return (0);
	return (remaining(a, b));
}

int	solving(t_list **a, t_list **b, int len)
{
	int	min;
	int	max;
	int	t;

	if (!pb(a, b, 1))
		return (0);
	if (!pb(a, b, 1))
		return (0);
	len -= 2;
	min = *((int *)find_min(*b)->content);
	max = *((int *)find_max(*b)->content);
	while (len > 3)
	{
		if (!alg_send_to_b(a, b, &min, &max))
			return (0);
		len--;
		t = check_if_sorted_alg(a);
		if (t == -1)
			return (0);
		if (t)
			break ;
	}
	return (help_solving(a, b));
}

int	solving_4(t_list **a, t_list **b)
{
	int	t;

	if (!pb(a, b, 1))
		return (0);
	t = check_if_sorted_alg(a);
	if (t == -1)
		return (0);
	if (!check_if_sorted_alg(a))
		if (!sa(a, 1))
			return (0);
	return (remaining(a, b));
}

int	inbetween(t_list **a, t_list **b, int len)
{
	int	t;

	if (len == 3)
	{
		t = check_if_sorted_alg(a);
		if (t == -1)
			return (0);
		if (!check_if_sorted_alg(a))
			if (!sa(a, 1))
				return (0);
		return (remaining(a, b));
	}
	else if (len == 4)
	{
		if (!solving_4(a, b))
			return (0);
	}
	else
	{
		if (!solving(a, b, len))
			return (0);
	}
	return (1);
}

int	solve2(t_list **a, t_list **b, int len)
{
	int	t;

	t = check_if_sorted(*a, len, 1);
	if (t == -1)
		return (0);
	if (len == 1 || t)
		return (1);
	if (len == 2)
	{
		t = check_if_sorted(*a, 2, 1);
		if (t == -1)
		{
			ft_lstclear(*a);
			return (0);
		}
		if (t == 0)
			if (!saver_lines(a))
				return (0);
		t = 1;
	}
	else
		t = inbetween(a, b, len);
	return (t);
}
