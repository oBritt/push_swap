/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:58:05 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/25 12:51:54 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next)
	{
		t = t->next;
	}
	t->next = new;
}

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

//     for (int i = 1; i <= 5; i++) {
// 		int *content = malloc(sizeof(int));
// 		*content = i;
//         t_list *new_node = ft_lstnew1(content);
// 		if (!head)
// 			head = new_node;
// 		else
//         	ft_lstadd_back(&head, new_node);
//     }
// 	while (head)
// 	{
// 		t_list *temp = head;
// 		printf("%i\n", *((int *)head->content));
// 		head = head->next;
// 		free(temp);
// 	}

// }