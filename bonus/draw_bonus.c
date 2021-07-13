/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:24:33 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/13 15:29:15 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exit(void *v)
{
	t_all *all;

	all = (t_all *)v;
	(all->size_b == 0 && ft_issorted(all->a, all->size_a)) ?
	write(1, "OK\n", 3) : write(1, "KO\n", 3);
	exit(0);
}

void	ft_mmpp(t_all *all, int x, int y, int color)
{
	char *ar;

	ar = all->adr + (y * all->ll + x * (all->bpp / 8));
	*(unsigned int *)ar = color;
}

void	ft_draw_line(t_all *all, int i)
{
	int		j;
	int		z;
	int		stop;
	int		color;
	double	end;

	end = 500 / all->size_pf;
	stop = end * (ft_memint(all->pf, all->a[i], all->size_pf) + 1);
	color = 0x000000 * (stop / 2) + 0x00ff00 * (stop / 2);
	z = -1;
	while (++z < end)
	{
		j = -1;
		while (++j < stop)
			ft_mmpp(all, j, i * end + z, color);
	}
}

void	ft_draw_line_b(t_all *all, int i)
{
	int		j;
	int		z;
	int		stop;
	int		color;
	double	end;

	end = 500 / all->size_pf;
	stop = end * (ft_memint(all->pf, all->b[i], all->size_pf) + 1);
	color = 0x000000 * (stop / 2) + 0x00ff00 * (stop / 2);
	z = -1;
	while (++z < end)
	{
		j = -1;
		while (++j < stop)
			ft_mmpp(all, j + 600, i * end + z, color);
	}
}

int		ft_draw_stacks(t_all *all)
{
	int		i;

	i = -1;
	pthread_mutex_unlock(&all->mutex);
	mlx_clear_window(all->mlx, all->win);
	all->img = mlx_new_image(all->mlx, 1200, 550);
	all->adr = mlx_get_data_addr(all->img, &all->bpp, &all->ll, &all->end);
	while (++i < all->size_a)
		ft_draw_line(all, i);
	i = -1;
	while (++i < all->size_b)
		ft_draw_line_b(all, i);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
	return (0);
}
