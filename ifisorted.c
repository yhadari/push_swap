/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifisorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:11:09 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 19:37:26 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ifisorted(t_stack *stack)
{
	int		size;

	size = stack->top;
	while (size--)
		if (stack->data[size + 1] > stack->data[size])
			return (0);
	return (1);
}
