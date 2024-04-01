/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_send_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:32:04 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:07:47 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra rb rra rrb rr rrr

// int	condition(int i1, int i2, int num)
// {
// 	if (i1 > num && num < i2)
// 		return (1);
// 	return (0);
// }

int	get_ind(int num, t_list **b, int *min, int *max)
{
	t_list	*cur;
	t_list	*prev;
	int		counter;
	int		i1;
	int		i2;

	prev = *b;
	counter = *((int *)ft_lstlast(*b)->content);
	if ((*(int *)prev->content) < num && counter > num)
		return (0);
	cur = prev->next;
	counter = 1;
	if (num < *min || num > *max)
		return (find_by_value_lst(*b, *max));
	i1 = (*(int *)prev->content);
	i2 = (*(int *)cur->content);
	while (!(i1 > num && i2 < num))
	{
		cur = cur->next;
		prev = prev->next;
		counter++;
		i1 = i2;
		i2 = (*(int *)cur->content);
	}
	return (counter);
}

void	better(int *news, int *old)
{
	long long	score1;
	long long	score2;
	int			i;

	score1 = 0;
	score2 = 0;
	i = 0;
	while (i < 6)
		score1 += news[i++];
	i = 0;
	while (i < 6)
		score2 += old[i++];
	i = 0;
	if (score2 > score1)
	{
		while (i < 6)
		{
			old[i] = news[i];
			i++;
		}
	}
}

int	reasign_b(t_list **a, t_list **b, int *max, int *min)
{
	if (*((int *)(*a)->content) > *max)
		*max = *((int *)(*a)->content);
	if (*((int *)(*a)->content) < *min)
		*min = *((int *)(*a)->content);
	if (!pb(a, b, 1))
		return (0);
	return (1);
}

int	alg_send_to_b(t_list **a, t_list **b, int *min, int *max)
{
	int		out[6];
	t_list	*copy;
	int		*current;
	int		i_a;
	int		i_b;

	set_to_max(out, 6);
	copy = *a;
	i_a = 0;
	while (copy)
	{
		i_b = get_ind(*((int *)copy->content), b, min, max);
		current = make_best(i_a, i_b, len_lst(*a) - i_a, len_lst(*b) - i_b);
		if (!current)
			return (0);
		better(current, out);
		copy = copy->next;
		i_a++;
		free(current);
	}
	if (!outputting(a, b, out))
		return (0);
	return (reasign_b(a, b, max, min));
}
