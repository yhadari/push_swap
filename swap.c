/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:39:28 by yhadari           #+#    #+#             */
/*   Updated: 2021/05/28 15:39:32 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int    sb(t_stack *stack)
{
    int swap;

    swap = 0;
    if (stack->top < 1)
        return (ft_perror("not enough\n"));
    swap = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = swap;
    write(1, "sb\n", 3);
    return (0);
}

int    sa(t_stack *stack)
{
    int swap;

    swap = 0;
    if (stack->top < 1)
        return (ft_perror("not enough\n"));
    swap = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = swap;
    write(1, "sa\n", 3);
    return (0);
}

int    ss(t_stack *a, t_stack *b)
{
    int swap;

    swap = 0;
    if (a->top < 1 || b->top < 1)
        return (ft_perror("not enough\n"));
    swap = a->data[a->top];
    a->data[a->top] = a->data[a->top - 1];
    a->data[a->top - 1] = swap;
    swap = b->data[b->top];
    b->data[b->top] = b->data[b->top - 1];
    b->data[b->top - 1] = swap;
    write(1, "ss\n", 3);
    return (0);
}