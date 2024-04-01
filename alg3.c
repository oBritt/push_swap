/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:24 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 21:22:36 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *a)
{
	int		min;
	t_list	*copy;
	t_list	*mini;

	min = 2147483647;
	copy = a;
	mini = NULL;
	while (copy)
	{
		if (*((int *)copy->content) < min)
		{
			min = *((int *)copy->content);
			mini = copy;
		}
		copy = copy->next;
	}
	return (mini);
}

t_list	*find_max(t_list *a)
{
	int		min;
	t_list	*copy;
	t_list	*mini;

	min = -2147483648;
	copy = a;
	mini = NULL;
	while (copy)
	{
		if (*((int *)copy->content) > min)
		{
			min = *((int *)copy->content);
			mini = copy;
		}
		copy = copy->next;
	}
	return (mini);
}

void	saving_lines25(t_list **copy, t_list *min, int *max)
{
	*copy = min;
	*copy = (*copy)->next;
	*max = *((int *)min->content);
}

int	check_if_sorted_alg(t_list **a)
{
	int		max;
	t_list	*min;
	t_list	*copy;

	min = find_min(*a);
	saving_lines25(&copy, min, &max);
	while (copy)
	{
		if (*((int *)copy->content) < max)
			return (0);
		max = *((int *)copy->content);
		copy = copy->next;
	}
	copy = *a;
	while (copy != min)
	{
		if (*((int *)copy->content) < max)
			return (0);
		max = *((int *)copy->content);
		copy = copy->next;
	}
	return (1);
}
