/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:37:59 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:01:44 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rra(t_stack *a, int index)
{
	int	i;
	int	swap;

	i = 0;
	if (a->top > 0)
	{
		while (i++ < a->top)
		{
			swap = a->data[i - 1];
			a->data[i - 1] = a->data[i];
			a->data[i] = swap;
		}
		if (index == 1)
			write(1, "rra\n", 4);
	}
	return (0);
}

int	rrb(t_stack *b, int index)
{
	int	i;
	int	swap;

	i = 0;
	if (b->top > 0)
	{
		while (i++ < b->top)
		{
			swap = b->data[i - 1];
			b->data[i - 1] = b->data[i];
			b->data[i] = swap;
		}
		if (index == 1)
			write(1, "rrb\n", 4);
	}
	return (0);
}

int	rrr(t_stack *a, t_stack *b, int index)
{
	int	i;
	int	swap;

	i = 0;
	if (a->top > 0 && b->top > 0)
	{
		while (i++ < a->top)
		{
			swap = a->data[i - 1];
			a->data[i - 1] = a->data[i];
			a->data[i] = swap;
		}
		i = 0;
		while (i++ < b->top)
		{
			swap = b->data[i - 1];
			b->data[i - 1] = b->data[i];
			b->data[i] = swap;
		}
		if (index == 1)
			write(1, "rrr\n", 4);
	}
	return (0);
}
