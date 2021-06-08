/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:39:28 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:12:39 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sb(t_stack *stack, int index)
{
	int	swap;

	if (stack->top > 0)
	{
		swap = 0;
		swap = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = swap;
		if (index == 1)
			write(1, "sb\n", 3);
	}
	return (0);
}

int	sa(t_stack *stack, int index)
{
	int	swap;

	if (stack->top > 0)
	{
		swap = 0;
		swap = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = swap;
		if (index == 1)
			write(1, "sa\n", 3);
	}
	return (0);
}

int	ss(t_stack *a, t_stack *b, int index)
{
	int	swap;

	if (a->top > 0 && b->top > 0)
	{
		swap = 0;
		swap = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = swap;
		swap = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = swap;
		if (index == 1)
			write(1, "ss\n", 3);
	}
	return (0);
}
