/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:40:43 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:11:34 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ifisduplicate(t_stack a)
{
	int	size;
	int	index;

	size = a.top;
	while (size >= 0)
	{
		index = size - 1;
		while (index >= 0)
		{
			if (a.data[size] == a.data[index--])
			{
				ft_perror("Error\n");
				exit(0);
			}
		}
		size--;
	}
}

int	peek(t_stack *stack)
{
	int	nb;

	nb = stack->data[stack->top];
	return (nb);
}

void	pop(t_stack *stack)
{
	if (stack->top >= 0)
		stack->top--;
	else
		ft_perror("Error\n");
}

void	push(t_stack *stack, int value)
{
	stack->top++;
	stack->data[stack->top] = value;
}
