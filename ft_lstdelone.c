/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:31:32 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/25 12:52:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// #include <stdlib.h>
// #include <stdio.h>

// void del(void * t)
// {
// 	free(t);
// }

// int main(){
// 	t_list	*first  = malloc(sizeof(t_list));
// 	t_list	*second = malloc(sizeof(t_list));
// 	t_list	*third = malloc(sizeof(t_list));

// 	int	*l1 = malloc(sizeof(int));
// 	int	*l2 = malloc(sizeof(int));
// 	int	*l3 = malloc(sizeof(int));

// 	*l1 = 1;
// 	*l2 = 2;
// 	*l3 = 3;
// 	first->content = l1;
// 	second->content = l2;
// 	third->content = l3;
// 	first->next = second;
// 	second->next = third;
// 	third->next = NULL;
// 	t_list *t;
// 	t = first;
// 	while (t)
// 	{
// 		printf("%i\n", *((int *)t->content));
// 		t = t->next;
// 	}
// 	ft_lstdelone(second, del);
// 	t = first;
// 	while (t)
// 	{
// 		printf("%i\n", *((int *)t->content));
// 		t = t->next;
// 	}
// }