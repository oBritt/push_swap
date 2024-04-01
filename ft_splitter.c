/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:35 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 17:25:57 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deleting_all(char ***s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		freeings(s[i], 10000000);
		i++;
	}
	free(s);
}

char	***ft_splitter(int argc, char **argv)
{
	char	***s;
	int		i;

	i = 0;
	s = malloc((argc) * sizeof(char **));
	if (!s)
		return (NULL);
	while (i < argc - 1)
	{
		s[i] = ft_split(argv[i + 1], ' ');
		if (!s[i])
		{
			deleting_all(s, i);
			return (NULL);
		}
		i++;
	}
	s[i] = NULL;
	return (s);
}
