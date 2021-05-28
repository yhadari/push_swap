/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:37:59 by yhadari           #+#    #+#             */
/*   Updated: 2021/05/28 16:38:00 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     rra(t_stack *a)
{
    int i;
    int swap;

    if (a->top < 1)
        return (ft_perror("not enough\n"));
    i = 0;
    while (i++ < a->top)
    {
        swap = a->data[i - 1];
        a->data[i - 1] = a->data[i];
        a->data[i] = swap;
    }
    write(1, "rra\n", 4);
    return (0);
}

int     rrb(t_stack *b)
{
    int i;
    int swap;

    if (b->top < 1)
        return (ft_perror("not enough\n"));
    i = 0;
    while (i++ < b->top)
    {
        swap = b->data[i - 1];
        b->data[i - 1] = b->data[i];
        b->data[i] = swap;
    }
    write(1, "rrb\n", 4);
    return (0);
}

int     rrr(t_stack *a, t_stack *b)
{
    int i;
    int swap;

    if (a->top < 1 || b->top < 1)
        return (ft_perror("not enough\n"));
    i = 0;
    while (i++ < a->top)
    {
        swap = a->data[i - 1];
        a->data[i - 1] = a->data[i];
        a->data[i] = swap;
    }
    i = 0;
    while (i++ < b->top)
    {
        swap = b->data[i - 1];
        b->data[i - 1] = b->data[i];
        b->data[i] = swap;
    }
    write(1, "rrr\n", 4);
    return (0);
}