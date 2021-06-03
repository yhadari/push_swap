/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstackb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:51:07 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 20:53:37 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_info	get_info(t_info info)
{
	if (info.max > info.min)
	{
		info.size = info.sizemax;
		info.minomax = 1;
	}
	if (info.min > info.max)
	{
		info.size = info.sizemin;
		info.minomax = 0;
	}
	if (info.min == info.max)
	{
		if (info.sizemin > info.sizemax)
		{
			info.size = info.sizemin;
			info.minomax = 0;
		}
		if (info.sizemin < info.sizemax)
		{
			info.size = info.sizemax;
			info.minomax = 1;
		}
	}
	return (info);
}

void	get_index(t_stack *b, t_info *info, t_sort *tab, int *i)
{
	*i = b->top;
	*tab = sort(*b);
	info->min = tab->str[0];
	info->max = tab->str[b->top];
}

t_info	max_min(t_stack *b)
{
	int		i;
	t_sort	tab;
	t_info	info;

	get_index(b, &info, &tab, &i);
	while (i >= 0)
	{
		if (b->data[i--] == info.max)
		{
			info.max = abs(i - b->top / 2 + 1);
			info.sizemax = i + 1;
			break ;
		}
	}
	i = b->top;
	while (i >= 0)
	{
		if (b->data[i--] == info.min)
		{
			info.min = abs(i - b->top / 2 + 1);
			info.sizemin = i + 1;
			break ;
		}
	}
	return (get_info(info));
}

void	rotate_min(int *size, t_stack *a, t_info info)
{
	if (info.minomax == 0)
	{
		(*size)++;
		ra(a);
	}
}

void	checkstackb(t_stack *a, t_stack *b, t_info info, int *size)
{
	int		nb;

	nb = 0;
	if (info.size == b->top)
	{
		pa(a, b);
		if (info.minomax == 0 && (*size)++)
			ra(a);
	}
	else if (info.size != b->top)
	{
		if (info.size > b->top / 2)
		{
			find_rotate(info.size, a, b, 2);
			rotate_min(size, a, info);
		}
		else
		{
			nb = info.size;
			while (nb-- >= 0)
				rrb(b);
			pa(a, b);
			rotate_min(size, a, info);
		}
	}
}
