/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:34:33 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/13 16:59:34 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker1(t_all *all, char **argv)
{
	int		i;
	int		j;

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
	return (0);
}

static int	checker_choice2(t_all *all, char *line, int i)
{
	if (ft_strncmp(line, "rra", i) == 0 && i == 3)
		rra(&all->a, all->size_a);
	else if (ft_strncmp(line, "rrb", i) == 0 && i == 3)
		rra(&all->b, all->size_b);
	else if (ft_strncmp(line, "rrr", i) == 0 && i == 3)
	{
		rra(&all->a, all->size_a);
		rra(&all->b, all->size_b);
	}
	else if (ft_strncmp(line, "pb", i) == 0 && i == 2)
		pa(&all->a, &all->b, &all->size_a, &all->size_b);
	else if (ft_strncmp(line, "pa", i) == 0 && i == 2)
		pa(&all->b, &all->a, &all->size_b, &all->size_a);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

static int	checker_choice(t_all *all, char *line, int i)
{
	if (ft_strncmp(line, "sa", i) == 0 && i == 2)
		sa(&all->a, all->size_a);
	else if (ft_strncmp(line, "sb", i) == 0 && i == 2)
		sa(&all->b, all->size_b);
	else if (ft_strncmp(line, "ss", i) == 0 && i == 2)
	{
		sa(&all->a, all->size_a);
		sa(&all->b, all->size_b);
	}
	else if (ft_strncmp(line, "ra", i) == 0 && i == 2)
		ra(&all->a, all->size_a);
	else if (ft_strncmp(line, "rb", i) == 0 && i == 2)
		ra(&all->b, all->size_b);
	else if (ft_strncmp(line, "rr", i) == 0 && i == 2)
	{
		ra(&all->a, all->size_a);
		ra(&all->b, all->size_b);
	}
	else
		return (checker_choice2(all, line, i));
	return (0);
}

static void *cycle(void *v)
{
	int		i;
	int		z;
	char	*line;
	t_all	*all;

	all = (t_all *)v;
	while ((z = get_next_line(0, &line)))
	{
		pthread_mutex_lock(&all->mutex);
		if (z == -1)
		{
			ft_putstr_fd("Error malloc\n", 2);
			exit(1);
		}
		i = ft_strlen(line);
		if (checker_choice(all, line, i))
			exit(1);
		free(line);
	}
	free(line);
	return (NULL);
}

int			main(int argc, char **argv)
{
	t_all		all;
	pthread_t 	thread;

	if (argc == 1 || argc > 501)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(1);
	}
	all.size_b = 0;
	all.size_a = argc - 1;
	all.size_pf = argc - 1;
	all.b = 0;
	pthread_mutex_init(&all.mutex, NULL);
	if (!(all.a = malloc(sizeof(int) * (all.size_a))))
		return (1);
	if (checker1(&all, argv) || ft_issorted(all.a, all.size_a) == 1)
		return (1);
	ft_perfect(&all);
	pthread_create(&thread, NULL, cycle, &all);
	pthread_detach(thread);
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 1200, 550, "checker");
	mlx_hook(all.win, 17, 0, ft_exit, &all);
	mlx_loop_hook(all.mlx, &ft_draw_stacks, &all);
	mlx_loop(all.mlx);
}
