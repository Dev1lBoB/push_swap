/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_then_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:08:37 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/13 22:56:40 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_three2(t_all *all)
{
	if (all->a[0] > all->a[2])
	{
		write(1, "ra\n", 3);
		ra(&all->a, all->size_a);
		return (1);
	}
	write(1, "sa\n", 3);
	sa(&all->a, all->size_a);
	return (1);
}

int			ft_sort_three(t_all *all)
{
	if (all->a[0] < all->a[1] || all->size_a == 2)
	{
		if (all->a[0] < all->a[1] && all->a[1] < all->a[2])
			return (1);
		write(1, "rra\n", 4);
		rra(&all->a, all->size_a);
		if (all->a[0] > all->a[1])
		{
			write(1, "sa\n", 3);
			sa(&all->a, all->size_a);
		}
		return (1);
	}
	if (all->a[1] > all->a[2])
	{
		write(1, "sa\n", 3);
		sa(&all->a, all->size_a);
		write(1, "rra\n", 4);
		rra(&all->a, all->size_a);
		return (1);
	}
	return (ft_sort_three2(all));
}

static int	ft_sort_five2(t_all *all)
{
	ft_sort_three(all);
	if (all->b[0] < all->b[1])
	{
		write(1, "sb\n", 3);
		sa(&all->b, all->size_b);
	}
	write(1, "pb\n", 3);
	pa(&all->a, &all->b, &all->size_a, &all->size_b);
	write(1, "pb\n", 3);
	pa(&all->a, &all->b, &all->size_a, &all->size_b);
	return (1);
}

int			ft_sort_five(t_all *all)
{
	int		fl;

	fl = 0;
	while (fl != 2)
		if (ft_memint(all->pf, all->a[0], all->size_pf) == 0
		|| ft_memint(all->pf, all->a[0], all->size_pf) == 1)
		{
			fl++;
			write(1, "pa\n", 3);
			pa(&all->b, &all->a, &all->size_b, &all->size_a);
		}
		else
		{
			write(1, "ra\n", 3);
			ra(&all->a, all->size_a);
		}
	return (ft_sort_five2(all));
}
