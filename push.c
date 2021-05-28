/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:41:44 by yhadari           #+#    #+#             */
/*   Updated: 2021/05/28 15:41:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int    pa(t_stack *a, t_stack *b)
{
    if (b->top < 0)
        return (ft_perror("stack is empty\n"));
    push(a, peek(b));
    pop(b);
    write(1, "pa\n", 3);
    return (0);
}

int    pb(t_stack *a, t_stack *b)
{
    if (a->top < 0)
        return (ft_perror("stack is empty\n"));
    push(b, peek(a));
    pop(a);
    write(1, "pb\n", 3);
    return (0);
}