/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:19:09 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/25 12:52:12 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	t = lst;
	if (!t)
		return (t);
	while (t->next)
	{
		t = t->next;
	}
	return (t);
}

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

//     for (int i = 100; i >=2; i--) {
// 		int *content = malloc(sizeof(int));
// 		*content = i;
//         t_list *new_node = ft_lstnew1(content);
//         ft_lstadd_front(&head, new_node);
//     }
// 	printf("%d\n\n", *((int *)ft_lstlast(head)->content));

// 	while (head)
// 	{
// 		t_list *temp = head;
// 		printf("%i\n", *((int *)head->content));
// 		head = head->next;
// 		free(temp);
// 	}

// }