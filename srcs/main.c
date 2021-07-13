/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:20:36 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/14 00:42:26 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_sortir(void *al)
{
	int		argc;
	t_all	*all;

	all = (t_all *)al;
	argc = all->min;
	if (argc <= 4)
		ft_sort_three(all);
	ft_perfect(all);
	if (argc > 4 && argc <= 6)
		ft_sort_five(all);
	all->min = -2147483649;
	all->max = -2147483649;
	if (argc > 6 && argc < 501)
		ft_sort_hundred(all, 1, 5);
	else if (argc > 6)
		ft_sort_hundred(all, 1, 11);
	return (NULL);
}

int		parser(char **argv, t_all *all, int j)
{
	int		i;

	i = 0;
	while (i < all->size_a)
	{
		j = -1;
		while (argv[i + 1][++j])
			if (j == 0 && argv[i + 1][j] == '-')
				continue ;
			else if (!ft_isdigit(argv[i + 1][j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
		if (ft_check_atoi(argv[i + 1]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		all->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_issorted(all->a, all->size_a))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all		all;

	all.min = argc;
	all.size_b = 0;
	all.size_a = argc - 1;
	all.size_pf = argc - 1;
	all.b = 0;
	if (!(all.a = malloc(sizeof(int) * (all.size_a))))
		return (1);
	if (parser(argv, &all, 0))
		return (1);
	ft_sortir(&all);
	return (1);
}
