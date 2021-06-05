/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkmetod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:41:05 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 19:05:35 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_max_toa2(t_stack *a, t_stack *b, int *size, int max)
{
	if (max == b->data[b->top])
	{
		pa(a, b, 1);
		*size = b->top;
	}
	else if (max == b->data[*size])
	{
		if (*size > b->top / 2)
			find_rotate(*size, a, b, 2);
		else
		{
			while ((*size)-- >= 0)
				rrb(b, 1);
			pa(a, b, 1);
		}
		*size = b->top;
	}
	else
		(*size)--;
}

void	push_max_toa(t_stack *a, t_stack *b)
{
	t_sort	tab;
	int		max;
	int		size;

	tab = sort(*b);
	max = tab.str[b->top];
	size = b->top;
	while (b->top >= 0)
	{
		tab = sort(*b);
		max = tab.str[b->top];
		push_max_toa2(a, b, &size, max);
	}
}

void	rotate(t_stack *a, t_stack *b, t_chunk *chunk)
{
	find_rotate(chunk->size_a, a, b, 1);
	chunk->index++;
}

void	push_chunk_tob(t_stack *a, t_stack *b, t_chunk *chunk, t_map *map)
{
	chunk->size_a = a->top;
	chunk->index = 0;
	while (chunk->size_a >= 0 && chunk->index < chunk->size)
	{
		if (isinchunk(map, a->data[chunk->size_a], chunk->nb, chunk->size))
		{
			if (chunk->size_a > a->top / 2)
				rotate(a, b, chunk);
			else
			{
				while (chunk->size_a-- >= 0)
				{
					rra(a, 1);
					if (isinchunk(map, a->data[a->top], chunk->nb, chunk->size))
					{
						pb(a, b, 1);
						chunk->index++;
					}
				}
			}
			chunk->size_a = a->top;
		}
		else
			chunk->size_a--;
	}
}

void	chunkmetod(t_sort buf, t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	t_map	*map;
	int		size;

	chunk.nb = 0;
	size = 0;
	chunk.size = (a->top + 1) / 10;
	map = malloc(sizeof(t_map) * a->top + 1);
	while (size <= a->top)
	{
		map[size].nb = buf.str[size];
		map[size++].chunk = chunk.nb;
		if (size % chunk.size == 0)
			chunk.nb++;
	}
	chunk.nb = 0;
	while (a->top >= 0)
	{
		push_chunk_tob(a, b, &chunk, map);
		chunk.nb++;
	}
}
