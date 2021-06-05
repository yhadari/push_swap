/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:08:49 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:05:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swaping(t_sort *tab, int *swap, int index)
{
	*swap = tab->str[index + 1];
	tab->str[index + 1] = tab->str[index];
	tab->str[index] = *swap;
}

t_sort	sort(t_stack a)
{
	int		i;
	int		index;
	int		swap;
	t_sort	tab;

	i = 0;
	index = a.top;
	swap = 0;
	tab.str = malloc (sizeof(int) * a.top + 1);
	while (i <= a.top)
		tab.str[i++] = a.data[index--];
	i = 0;
	while (i++ <= a.top + 1)
	{
		index = a.top;
		while (index-- > 0)
		{
			if (tab.str[index + 1] < tab.str[index])
				swaping(&tab, &swap, index);
		}
	}
	tab.med = tab.str[(a.top + 1) / 2];
	return (tab);
}
