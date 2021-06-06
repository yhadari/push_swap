/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinchunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:25:42 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 19:25:49 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	isinchunk(t_map *map, int nb, int chunk, int sizechunk)
{
	int	size;

	size = chunk * sizechunk;
	while (sizechunk-- > 0)
		if (nb == map[size++].nb)
			return (1);
	return (0);
}
