/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:31:04 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 14:13:56 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	saver_lines(t_list **a)
{
	if (!sa(a, 1))
	{
		ft_lstclear(*a);
		return (0);
	}
	return (1);
}
