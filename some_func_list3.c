/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_func_list3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:00:42 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/26 12:20:32 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_help_md(t_list **temp, t_list **comb)
{
	(*temp)->next = *comb;
	*comb = (*comb)->next;
}

t_list	*helper_mer(t_list *out, t_list *temp, t_list *first, t_list *second)
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
			if (*((int *)first->content) > *((int *)second->content))
				help_help_md(&temp, &first);
			else
				help_help_md(&temp, &second);
			temp = temp->next;
			temp->next = NULL;
		}
	}
	return (out);
}

t_list	*merge_d(t_list *first, t_list *second)
{
	t_list	*out;
	t_list	*temp;

	if (*((int *)first->content) > *((int *)second->content))
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
	return (helper_mer(out, temp, first, second));
}
