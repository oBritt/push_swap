/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:44:40 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/30 19:05:58 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *temp, int len)
{
	t_list	*a;
	t_list	*b;
	int		t;

	if (len == 1)
		return (1);
	a = create(temp, len);
	if (!a)
		return (0);
	b = NULL;
	t = solve2(&a, &b, len);
	ft_lstclear(a);
	ft_lstclear(b);
	return (t);
}
