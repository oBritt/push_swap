/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:34:50 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/27 19:44:52 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}

int	len_lst(t_list *head)
{
	t_list	*copy;
	int		t;

	copy = head;
	t = 0;
	while (copy)
	{
		copy = copy->next;
		t++;
	}
	return (t);
}

int	find_by_value_lst(t_list *t, int value)
{
	int		it;
	t_list	*copy;

	copy = t;
	it = 0;
	while (*((int *)copy->content) != value)
	{
		copy = copy->next;
		it++;
	}
	if (!copy)
		return (-1);
	return (it);
}

// #include <stdio.h>

// int main(){
// 	int te = 5;
// 	t_list *t = ft_lstnew(&te);
// 	printf("%i\n", *((int * )t->content));
// }