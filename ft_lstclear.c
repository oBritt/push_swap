/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:32 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/30 18:53:24 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*t;
	t_list	*temp;

	if (!lst)
		return ;
	t = lst;
	while (t)
	{
		temp = t;
		t = t->next;
		free(temp);
	}
}

// void	del(void *t)
// {
// 	free(t);
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
// 		printf("%i\n", *((int *)t->content));
// 		t = t->next;
// 	}
// 	t = head->next->next;
// 	ft_lstclear(&t, del);
// 	while (head)
// 	{
// 		printf("%i\n", *((int *) head->content));
// 		head = head->next;
// 	}
// }