/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:31:08 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/06 15:10:15 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	random_3(t_stack *stack)
{
	if (stack->data[0] > stack->data[stack->top]
		&& stack->data[stack->top] > stack->data[stack->top - 1])
		sa(stack, 1);
	if (stack->data[stack->top] > stack->data[stack->top - 1]
		&& stack->data[stack->top - 1] > stack->data[0])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	if (stack->data[stack->top] > stack->data[0]
		&& stack->data[0] > stack->data[stack->top - 1])
		ra(stack, 1);
	if (stack->data[stack->top - 1] > stack->data[0]
		&& stack->data[0] > stack->data[stack->top])
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	if (stack->data[stack->top - 1] > stack->data[stack->top]
		&& stack->data[stack->top] > stack->data[0])
		rra(stack, 1);
}

void	random_2(t_stack *stack)
{
	if (stack->data[stack->top] > stack->data[0])
		sa(stack, 1);
}

void	random_5(t_stack *a, t_stack *b)
{
	int		size;
	t_sort	tab;

	tab = sort(*a);
	size = a->top;
	while (a->top > 2 && size >= 0)
	{
		if (a->data[size] < tab.med && size == a->top)
			pushtop_a_tob(a, b, &size);
		else if (a->data[size] < tab.med && size != a->top)
		{
			if (size > a->top / 2)
				find_rotate(size, a, b, 1);
			else
				find_rrotate(size, a, b, tab);
			size = a->top;
		}
		else
			size--;
	}
	ft_free(&tab);
	random_3(a);
	push_max_toa(a, b);
}

void	random_4(t_stack *a, t_stack *b)
{
	int		min;
	int		size;
	t_sort	tab;

	tab = sort(*a);
	min = tab.str[0];
	size = a->top;
	while (size >= 0)
	{
		if (a->data[size] == min)
		{
			if (size > a->top / 2)
				find_rotate(size, a, b, 1);
			else
				find_rrotate(size, a, b, tab);
			break ;
		}
		size--;
	}
	ft_free(&tab);
	random_3(a);
	pa(a, b, 1);
}

int	randomsort(t_stack *a, t_stack *b, int size)
{
	if (size == 3)
		random_3(a);
	if (size == 2)
		random_2(a);
	if (size == 5)
		random_5(a, b);
	if (size == 4)
		random_4(a, b);
	return (0);
}
