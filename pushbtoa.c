/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:09:04 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 20:46:49 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushbtoa(t_stack *a, t_stack *b, int c)
{
	t_index	index;
	t_info	info;
	int		size;

	size = a->top;
	index.top = a->data[a->top];
	index.zero = a->data[0];
	index.size = a->top + 1;
	while (b->top >= 0)
	{
		info = max_min(b);
		checkstackb(a, b, info, &size);
	}
	size = a->top - size;
	while (size--)
		ra(a, 1);
	if (c == 1)
		while (index.size--)
			pb(a, b, 1);
}
