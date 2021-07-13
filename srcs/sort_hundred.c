/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:14:03 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/13 22:27:32 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_hundred2(t_all *all, int *i, int *fl, int *fl2)
{
	*fl = -1;
	*i = -1;
	while (++(*i) < all->size_a)
		if (ft_memint(all->pf, all->a[*i], all->size_pf) >= all->ch_s
		&& ft_memint(all->pf, all->a[*i], all->size_pf) <= all->ch_f
		&& (*fl == -1 || all->size_a - *i < *fl))
			*fl = *i;
	*fl2 = -1;
	*i = -1;
	while (++(*i) < all->size_b)
		if (all->b[*i] < all->a[*fl] &&
		(*fl2 == -1 || all->b[*i] > all->b[*fl2]))
			*fl2 = *i;
	*i = -1;
	if (*fl2 == -1 && all->size_b)
		while (++(*i) < all->size_b)
			if (*fl2 == -1 || all->b[*i] < all->b[*fl2 - 1])
				*fl2 = *i + 1;
}

void		ft_sort_hundred3(t_all *all, int *fl, int *fl2)
{
	while (*fl2 < all->size_b && *fl < all->size_a)
	{
		(*fl2)++;
		(*fl)++;
		write(1, "rrr\n", 4);
		rrr(&all->a, &all->b, all->size_a, all->size_b);
	}
	while ((*fl)++ < all->size_a)
	{
		write(1, "rra\n", 4);
		rra(&all->a, all->size_a);
	}
	while ((*fl2)++ < all->size_b)
	{
		write(1, "rrb\n", 4);
		rra(&all->b, all->size_b);
	}
}

void		ft_sort_hundred4(t_all *all, int *fl, int *fl2)
{
	while (*fl2 && *fl)
	{
		(*fl2)--;
		(*fl)--;
		write(1, "rr\n", 3);
		rr(&all->a, &all->b, all->size_a, all->size_b);
	}
	while ((*fl2)--)
	{
		write(1, "rb\n", 3);
		ra(&all->b, all->size_b);
	}
	while ((*fl)--)
	{
		write(1, "ra\n", 3);
		ra(&all->a, all->size_a);
	}
}

static void	ft_sort_hundred6(t_all *all, int *fl)
{
	if (*fl > all->size_a / 2)
		while ((*fl)++ < all->size_a)
		{
			write(1, "rra\n", 4);
			rra(&all->a, all->size_a);
		}
	else if (*fl != -1)
		while ((*fl)--)
		{
			write(1, "ra\n", 3);
			ra(&all->a, all->size_a);
		}
}

void		ft_sort_hundred5(t_all *all, int *fl, int *fl2)
{
	if (*fl2 != -1 && *fl2 > all->size_b / 2)
		while ((*fl2)++ < all->size_b)
		{
			write(1, "rrb\n", 4);
			rra(&all->b, all->size_b);
		}
	else if (*fl2 != -1)
		while ((*fl2)-- > 0)
		{
			write(1, "rb\n", 3);
			ra(&all->b, all->size_b);
		}
	ft_sort_hundred6(all, fl);
}
