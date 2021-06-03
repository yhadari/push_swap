/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushatob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:41:09 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 19:40:13 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	find_rotate(int size, t_stack *a, t_stack *b, int index)
{
	int		nb;

	nb = size;
	if (index == 1)
	{
		while (nb++ < a->top)
			ra(a);
		pb(a, b);
	}
	if (index == 2)
	{
		while (nb++ < b->top)
			rb(b);
		pa(a, b);
	}
}

void	find_rrotate(int size, t_stack *a, t_stack *b, t_sort tab)
{
	int		nb;

	nb = size;
	while (nb-- >= 0)
	{
		rra(a);
		if (a->data[a->top] < tab.med)
			pb(a, b);
	}
}

void	pushatob(t_sort tab, t_stack *a, t_stack *b)
{
	int		size;

	size = a->top;
	while (a->top >= 0 && size >= 0)
	{
		if (a->data[size] < tab.med && size == a->top)
		{
			pb(a, b);
			size = a->top;
		}
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
}
