/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:54:47 by wpersimm          #+#    #+#             */
/*   Updated: 2021/03/13 06:53:12 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa2(int **b, int *size_b, int **tmp1)
{
	int		i;

	if (*size_b != 0)
	{
		if (!(*tmp1 = malloc(sizeof(int) * (*size_b))))
		{
			exit(0);
			write(2, "Error: malloc\n", 14);
		}
		i = 0;
		while (++i < (*size_b + 1))
			(*tmp1)[i - 1] = (*b)[i];
	}
	else
		*tmp1 = 0;
}

void		pa(int **a, int **b, int *size_a, int *size_b)
{
	int		i;
	int		*tmp1;
	int		*tmp2;

	if (*size_b == 0)
		return ;
	(*size_b)--;
	(*size_a)++;
	pa2(b, size_b, &tmp1);
	if (!(tmp2 = malloc(sizeof(int) * (*size_a))))
	{
		exit(0);
		write(2, "Error: malloc\n", 14);
	}
	i = 0;
	tmp2[0] = (*b)[0];
	while (++i < (*size_a))
		tmp2[i] = (*a)[i - 1];
	free(*a);
	free(*b);
	*a = tmp2;
	*b = tmp1;
}
