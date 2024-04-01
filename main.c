/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:46:40 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 20:32:03 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hel(int *temp, char ***s, int argc, int *err)
{
	if (!err && !temp)
		*err = 1;
	if (temp)
	{
		if (!*err && !check_argv(temp, s))
			*err = 1;
		if (!*err && !check_unique(temp, argc))
			*err = 1;
	}
}

void	delete_all(int *temp, char ***s)
{
	if (temp)
		free(temp);
	if (s)
		deleting_all(s, 1e9);
}

int	main(int argc, char *argv[])
{
	int		*temp;
	char	***s;
	int		err;

	if (argc > 1)
	{
		err = 0;
		s = ft_splitter(argc, argv);
		if (!s)
			err = 1;
		argc = get_len_s(s);
		if (argc == 0)
		{
			deleting_all(s, 1e9);
			return (0);
		}
		temp = malloc(sizeof(int) * argc);
		hel(temp, s, argc, &err);
		if (!err && !push_swap(temp, argc))
			err = 1;
		delete_all(temp, s);
		if (err)
			errors();
	}
}
