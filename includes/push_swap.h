/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:44:55 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/13 15:29:45 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "libft.h"
# include "mlx.h"

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	void			*adr;
	void			*img;
	int				bpp;
	int				ll;
	int				end;
	int				*a;
	int				*b;
	int				*pf;
	int				ch_s;
	int				ch_f;
	int				size_a;
	int				size_b;
	int				size_pf;
	long			min;
	long			max;
	pthread_mutex_t mutex;
}					t_all;

void				ft_swap(int *a, int *b);
void				sa(int **a, int size_a);
void				ra(int **a, int size_a);
void				rra(int **a, int size_a);
void				pa(int **a, int **b, int *size_a, int *size_b);
void				rr(int **a, int **b, int size_a, int size_b);
void				rrr(int **a, int **b, int size_a, int size_b);

void				ft_perfect(t_all *all);
int					ft_memint(int *a, int c, int size_a);
int					ft_check_atoi(char *str);
int					ft_issorted(int *a, int size_a);

int					ft_sort_three(t_all *all);
int					ft_sort_five(t_all *all);

int					ft_sort_hundred(t_all *all, int ch, int size);
void				ft_sort_hundred2(t_all *all, int *i, int *fl, int *fl2);
void				ft_sort_hundred3(t_all *all, int *fl, int *fl2);
void				ft_sort_hundred4(t_all *all, int *fl, int *fl2);
void				ft_sort_hundred5(t_all *all, int *fl, int *fl2);

void				ft_mmpp(t_all *all, int x, int y, int color);
void				ft_draw_line(t_all *all, int i);
void				ft_draw_line_b(t_all *all, int i);
int					ft_draw_stacks(t_all *all);
int					ft_exit(void *);

#endif
