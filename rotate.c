/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:55:20 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:02:37 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra(t_stack *a, int index)
{
	int	i;
	int	swap;

	if (a->top > 0)
	{
		i = a->top;
		while (i--)
		{
			swap = a->data[i + 1];
			a->data[i + 1] = a->data[i];
			a->data[i] = swap;
		}
		if (index == 1)
			write(1, "ra\n", 3);
	}
	return (0);
}

int	rb(t_stack *b, int index)
{
	int	i;
	int	swap;

	if (b->top > 0)
	{
		i = b->top;
		while (i--)
		{
			swap = b->data[i + 1];
			b->data[i + 1] = b->data[i];
			b->data[i] = swap;
		}
		if (index == 1)
			write(1, "rb\n", 3);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b, int index)
{
	int	i;
	int	swap;

	if (a->top > 0 && b->top > 0)
	{
		i = a->top;
		while (i--)
		{
			swap = a->data[i + 1];
			a->data[i + 1] = a->data[i];
			a->data[i] = swap;
		}
		i = b->top;
		while (i--)
		{
			swap = b->data[i + 1];
			b->data[i + 1] = b->data[i];
			b->data[i] = swap;
		}
		if (index == 1)
			write(1, "rr\n", 3);
	}
	return (0);
}
