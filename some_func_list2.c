/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_func_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:11:34 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/26 13:16:49 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_list	*temp, int len1)
{
	t_list	*copy;
	int		len;
	int		t;
	t_list	*it;

	copy = ft_lstmap_in(temp, len1);
	if (!copy)
		return (2147483647);
	copy = sorting(copy, 1);
	it = copy;
	len = len_lst(copy);
	len /= 2;
	t = 0;
	while (t < len)
	{
		t++;
		it = it->next;
	}
	t = *((int *)it->content);
	ft_lstclear(copy);
	return (t);
}

t_list	*ft_lstmap_in(t_list *lst, int len)
{
	t_list	*t;
	t_list	*head;
	t_list	*new_list;
	int		i;

	t = lst;
	head = NULL;
	i = 0;
	while (i < len)
	{
		new_list = ft_lstnew(t->content);
		if (!new_list)
		{
			ft_lstclear(head);
			return (NULL);
		}
		ft_lstadd_front(&head, new_list);
		t = t->next;
		i++;
	}
	return (reverse(head));
}

void	moving_25_lines(int *i, t_list **copy, t_list **copy2)
{
	*i = *i + 1;
	*copy = ((*copy)->next);
	*copy2 = ((*copy2)->next);
}

int	check_if_sorted(t_list *head, int len, int inc)
{
	t_list	*copy;
	t_list	*sorted;
	t_list	*copy2;
	int		i;
	int		ans;

	ans = 1;
	copy = ft_lstmap_in(head, len);
	if (!copy)
		return (-1);
	sorted = sorting(copy, inc);
	copy = head;
	copy2 = sorted;
	i = 0;
	while (i < len)
	{
		if (*((int *)copy->content) != *((int *)copy2->content))
		{
			ans = 0;
			break ;
		}
		moving_25_lines(&i, &copy, &copy2);
	}
	ft_lstclear(sorted);
	return (ans);
}
