/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_send_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:57:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 22:08:00 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ind_a(int num, t_list **a, int *min, int *max)
{
	t_list	*cur;
	t_list	*prev;
	int		counter;
	int		i1;
	int		i2;

	prev = *a;
	counter = *((int *)(ft_lstlast(*a)->content));
	if (*((int *)prev->content) > num && num > counter)
		return (0);
	if (num > *max || num < *min)
		return (find_by_value_lst(*a, *min));
	counter = 1;
	cur = prev->next;
	i1 = *((int *)prev->content);
	i2 = *((int *)cur->content);
	while (!(i1 < num && i2 > num))
	{
		cur = cur->next;
		prev = prev->next;
		counter++;
		i1 = *((int *)prev->content);
		i2 = *((int *)cur->content);
	}
	return (counter);
}

int	reasign(t_list **a, t_list **b, int *max, int *min)
{
	if (*((int *)(*b)->content) > *max)
		*max = *((int *)(*b)->content);
	if (*((int *)(*b)->content) < *min)
		*min = *((int *)(*b)->content);
	if (!pa(a, b, 1))
		return (0);
	return (1);
}

int	alg_send_to_a(t_list **a, t_list **b, int *min, int *max)
{
	int		out[6];
	t_list	*copy;
	int		*current;
	int		i_a;
	int		i_b;

	set_to_max(out, 6);
	copy = *b;
	i_b = 0;
	while (copy)
	{
		i_a = get_ind_a(*((int *)copy->content), a, min, max);
		current = make_best(i_a, i_b, len_lst(*a) - i_a, len_lst(*b) - i_b);
		if (!current)
			return (0);
		better(current, out);
		copy = copy->next;
		i_b++;
		free(current);
	}
	if (!outputting(a, b, out))
		return (0);
	return (reasign(a, b, max, min));
}

int	remaining(t_list **a, t_list **b)
{
	int	max;
	int	min;
	int	len;
	int	i;
	int	output[6];

	min = *((int *)find_min(*a)->content);
	max = *((int *)find_max(*a)->content);
	len = len_lst(*b);
	while (len)
	{
		if (!alg_send_to_a(a, b, &min, &max))
			return (0);
		len--;
	}
	len = len_lst(*a);
	i = find_by_value_lst(*a, min);
	set_to_zero_ind(output, 6);
	if (len - i > i)
		output[0] = i;
	else
		output[2] = len - i;
	if (!outputting(a, b, output))
		return (0);
	return (1);
}
