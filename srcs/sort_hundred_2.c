/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:20:01 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/13 22:27:55 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_hundred7(t_all *all, int *i, int *fl, int *fl2)
{
	ft_sort_hundred2(all, i, fl, fl2);
	if (*fl != -1 && *fl2 != -1 &&
	((*fl2 > all->size_b / 2 && all->size_a - (all->size_b - *fl2) - *fl < *fl)
	||
	(*fl > all->size_a / 2 && all->size_b - (all->size_a - *fl) - *fl2 < *fl2)))
		ft_sort_hundred3(all, fl, fl2);
	else if (*fl != -1 && *fl2 != -1 &&
			((*fl2 <= all->size_b / 2 && *fl - *fl2 < all->size_a - *fl) ||
			(*fl <= all->size_a / 2 && *fl2 - *fl < all->size_b - *fl2)))
		ft_sort_hundred4(all, fl, fl2);
	else
		ft_sort_hundred5(all, fl, fl2);
	write(1, "pa\n", 3);
	pa(&all->b, &all->a, &all->size_b, &all->size_a);
}

static void	ft_sort_hundred8(t_all *all, int *fl)
{
	*fl = ft_memint(all->b, all->pf[all->size_b - 1], all->size_b);
	if (*fl > all->size_b / 2)
		while ((*fl)++ < all->size_b)
		{
			write(1, "rrb\n", 4);
			rra(&all->b, all->size_b);
		}
	else
		while ((*fl)--)
		{
			write(1, "rb\n", 3);
			ra(&all->b, all->size_b);
		}
	write(1, "pb\n", 3);
	pa(&all->a, &all->b, &all->size_a, &all->size_b);
}

int			ft_sort_hundred(t_all *all, int ch, int size)
{
	int		i;
	int		fl;
	int		fl2;
	int		count;

	all->ch_s = all->size_pf / size * (ch - 1);
	if (ch != size)
		all->ch_f = all->size_pf / size * ch - 1;
	else
		all->ch_f = all->size_pf - 1;
	count = all->ch_s;
	while (count++ <= all->ch_f)
		ft_sort_hundred7(all, &i, &fl, &fl2);
	if (ch != size)
		ft_sort_hundred(all, ch + 1, size);
	if (ch != 1)
		return (1);
	count = all->size_pf;
	while (count-- > 0)
		ft_sort_hundred8(all, &fl);
	return (1);
}
