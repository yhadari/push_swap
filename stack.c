/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:40:43 by yhadari           #+#    #+#             */
/*   Updated: 2021/05/28 15:40:45 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     peek(t_stack *stack)
{
    int nb;

    nb = stack->data[stack->top];
    return (nb);
}

void    pop(t_stack *stack)
{
    if (stack->top >= 0)
        stack->top--;
}

void    push(t_stack *stack, int value)
{
    stack->top++;
    stack->data[stack->top] = value;
}