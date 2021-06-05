/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:41:44 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 19:38:29 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa(t_stack *a, t_stack *b, int index)
{
	if (b->top >= 0)
	{
		if (b->top < 0)
			return (ft_perror("Error\n"));
		push(a, peek(b));
		pop(b);
		if (index == 1)
			write(1, "pa\n", 3);
	}
	return (0);
}

int	pb(t_stack *a, t_stack *b, int index)
{
	if (a->top >= 0)
	{
		if (a->top < 0)
			return (ft_perror("Error\n"));
		push(b, peek(a));
		pop(a);
		if (index == 1)
			write(1, "pb\n", 3);
	}
	return (0);
}
