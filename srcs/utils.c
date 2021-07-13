/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:03:51 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/13 07:07:06 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_memint(int *a, int c, int size_a)
{
	int		i;

	i = -1;
	while (++i < size_a)
	{
		if (a[i] == c)
			return (i);
	}
	return (-1);
}

int		ft_check_atoi(char *str)
{
	int						i;
	unsigned long int		res;

	res = 0;
	i = -1;
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[++i]))
		res = res * 10 + str[i] - 48;
	if (ft_strlen(str) > 11 ||
	(res > 2147483647 && str[0] != '-') || res > 2147483648)
		return (1);
	return (0);
}

int		ft_issorted(int *a, int size_a)
{
	int		i;

	i = -1;
	while (++i < size_a - 1)
		if (ft_memint(a + i + 1, a[i], size_a - i - 1) != -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	i = -1;
	while (++i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (2);
}

void	ft_perfect(t_all *all)
{
	int		i;

	all->pf = malloc(all->size_a * sizeof(int));
	i = -1;
	while (++i < all->size_a)
		all->pf[i] = all->a[i];
	i = -1;
	while (++i < all->size_a - 1)
		if (all->pf[i] > all->pf[i + 1])
		{
			ft_swap(&all->pf[i], &all->pf[i + 1]);
			i = -1;
		}
}
