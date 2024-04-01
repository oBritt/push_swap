/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:28:46 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/25 14:25:53 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*reverse(t_list *head)
{
	t_list	*t;
	t_list	*temp;

	t = head;
	if (!t || !t->next)
		return (t);
	while (t->next)
	{
		temp = t->next;
		t->next = t->next->next;
		temp->next = head;
		head = temp;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst)
{
	t_list	*t;
	t_list	*head;
	t_list	*new_list;

	t = lst;
	head = NULL;
	while (t)
	{
		new_list = ft_lstnew(t->content);
		if (!new_list || !new_list->content)
		{
			ft_lstclear(head);
			return (NULL);
		}
		ft_lstadd_front(&head, new_list);
		t = t->next;
	}
	return (reverse(head));
}

// void	del(void *t)
// {
// 	free (t);
// }

// void	*increment_by_one(void *t)
// {
// 	int *ptr = (int *)t;
// 	(*ptr)++;
// 	return ptr;
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

// #include <stdio.h>

// t_list	*ft_lstnew1(void *content)
// {
// 	t_list	*t;

// 	t = malloc(sizeof(t_list));
// 	t->content = content;
// 	t->next = NULL;
// 	return (t);
// }

// int main() {
//     t_list *head = NULL;

//     for (int i = 5; i >= 1; i--) {
// 		int *content = malloc(sizeof(int));
// 		*content = i;
//         t_list *new_node = ft_lstnew1(content);
//         ft_lstadd_front(&head, new_node);
//     }
// 	t_list *t = head;
// 	while (t)
// 	{
// 		printf("%i\n", *((int *) t->content));
// 		t = t->next;
// 	}
// 	printf("\n\n");
// 	t_list *s = ft_lstmap(head, increment_by_one, del);

// 	while (s)
// 	{
// 		printf("%i\n", *((int *) s->content));
// 		s = s->next;
// 	}
// }