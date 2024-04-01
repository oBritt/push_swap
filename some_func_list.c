/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_func_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:03:33 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/25 17:04:31 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create(int	*temp, int len)
{
	t_list	*out;
	int		it;
	t_list	*t;

	it = 0;
	out = NULL;
	while (it < len)
	{
		t = ft_lstnew(&temp[it]);
		if (!t)
		{
			ft_lstclear(out);
			return (NULL);
		}
		ft_lstadd_front(&out, t);
		it++;
	}
	return (reverse(out));
}

void	help_help_m(t_list **temp, t_list **comb)
{
	(*temp)->next = *comb;
	*comb = (*comb)->next;
}

t_list	*helper_merge(t_list *out, t_list *temp, t_list *first, t_list *second)
{
	while (1)
	{
		if (!first && !second)
			break ;
		else if (!first)
		{
			temp->next = second;
			break ;
		}
		else if (!second)
		{
			temp->next = first;
			break ;
		}
		else
		{
			if (*((int *)first->content) < *((int *)second->content))
				help_help_m(&temp, &first);
			else
				help_help_m(&temp, &second);
			temp = temp->next;
			temp->next = NULL;
		}
	}
	return (out);
}

t_list	*merge(t_list *first, t_list *second)
{
	t_list	*out;
	t_list	*temp;

	if (*((int *)first->content) < *((int *)second->content))
	{
		out = first;
		first = first->next;
		out->next = NULL;
	}
	else
	{
		out = second;
		second = second->next;
		out->next = NULL;
	}
	temp = out;
	return (helper_merge(out, temp, first, second));
}

t_list	*sorting(t_list *head, int inc)
{
	int		len;
	t_list	*second;
	t_list	*prev;
	int		it;

	len = len_lst(head);
	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	it = 1;
	second = head->next;
	prev = head;
	while (it < len / 2)
	{
		second = second->next;
		prev = prev->next;
		it++;
	}
	prev->next = NULL;
	if (inc)
		return (merge(sorting(head, inc), sorting(second, inc)));
	return (merge_d(sorting(head, inc), sorting(second, inc)));
}
