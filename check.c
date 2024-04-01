/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:56:12 by obrittne          #+#    #+#             */
/*   Updated: 2024/03/28 17:14:33 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digits(char *str1)
{
	int		it;
	int		save_empty;
	char	*str;

	str = str1;
	if (*str == '-')
		str++;
	it = 0;
	save_empty = 0;
	while (str[it])
	{
		if (!(str[it] >= '0' && str[it] <= '9'))
			return (0);
		it++;
		save_empty = 1;
	}
	if (save_empty)
		return (1);
	return (0);
}

static int	check_s(char *str, int *num, int minus, int len)
{
	long long	out;

	if (*str == '-')
	{
		str++;
		minus++;
	}
	while (str[len])
		len++;
	if (len > 10)
		return (0);
	len = 0;
	out = 0;
	while (str[len])
	{
		out = (out * 10) + str[len] - '0';
		len++;
	}
	if (minus)
		out = -out;
	if (!(out >= -2147483648 && out <= 2147483647))
		return (0);
	*num = out;
	return (1);
}

int	get_len_s(char ***s)
{
	int	it;
	int	i;
	int	ind;

	it = 0;
	ind = 0;
	while (s[it])
	{
		i = 0;
		while (s[it][i])
		{
			i++;
			ind++;
		}
		it++;
	}
	return (ind);
}

int	check_argv(int *temp, char ***s)
{
	int	it;
	int	i;
	int	num;
	int	ind;

	it = 0;
	ind = 0;
	while (s[it])
	{
		i = 0;
		while (s[it][i])
		{
			if (!(check_digits(s[it][i]) && check_s(s[it][i], &num, 0, 0)))
				return (0);
			temp[ind] = num;
			ind++;
			i++;
		}
		it++;
	}
	return (1);
}

int	check_unique(int *temp, int len)
{
	int	it1;
	int	it2;

	it1 = 0;
	while (it1 < len - 1)
	{
		it2 = it1 + 1;
		while (it2 < len)
		{
			if (temp[it1] == temp[it2])
				return (0);
			it2++;
		}
		it1++;
	}
	return (1);
}
