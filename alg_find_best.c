/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_find_best.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:39:59 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/27 22:06:41 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra rb rra rrb rr rrr

int	**freeing(int **out, int ind)
{
	int	it;

	it = 0;
	while (it < ind)
	{
		free(out[it]);
		it++;
	}
	free(out);
	return (NULL);
}

int	**allocating(void)
{
	int	**out;
	int	i;

	out = malloc(4 * sizeof(int *));
	if (!out)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		out[i] = malloc(6 * sizeof(int));
		if (!out[i])
			return (freeing(out, i));
		set_to_zero_ind(out[i], 6);
		i++;
	}
	return (out);
}

void	better1(int	*news, int *old)
{
	int			i;
	long long	score1;
	long long	score2;

	i = 0;
	score1 = 0;
	score2 = 0;
	while (i < 6)
		score1 += news[i++];
	i = 0;
	while (i < 6)
		score2 += old[i++];
	i = 0;
	if (score2 > score1)
	{
		while (i < 6)
		{
			old[i] = news[i];
			i++;
		}
	}
}

void	best(int **out, int *temp)
{
	int	mini;

	set_to_max(temp, 6);
	mini = min(out[0][0], out[0][1]);
	out[0][0] -= mini;
	out[0][1] -= mini;
	out[0][4] = mini;
	mini = min(out[3][2], out[3][3]);
	out[3][2] -= mini;
	out[3][3] -= mini;
	out[3][5] = mini;
	mini = 0;
	while (mini < 4)
	{
		better1(out[mini], temp);
		mini++;
	}
}

int	*make_best(int ind_a, int ind_b, int len_a, int len_b)
{
	int	**out;
	int	*temp;

	temp = malloc(6 * sizeof(int));
	if (!temp)
		return (NULL);
	out = allocating();
	if (!out)
	{
		free(temp);
		return (NULL);
	}
	out[0][0] = ind_a;
	out[0][1] = ind_b;
	out[1][3] = len_b;
	out[1][0] = ind_a;
	out[2][1] = ind_b;
	out[2][2] = len_a;
	out[3][3] = len_b;
	out[3][2] = len_a;
	best(out, temp);
	freeing(out, 4);
	return (temp);
}
