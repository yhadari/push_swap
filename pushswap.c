/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:00:34 by yhadari           #+#    #+#             */
/*   Updated: 2021/05/26 15:00:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str++)
        i++;
    return (i);
}

int     ft_perror(char *str)
{
    write(1, str, ft_strlen(str)+1);
    return (0);
}

void    display(t_stack stack)
{
    int i;

    i = stack.top;
    while(i >= 0)
        printf("%d ", stack.data[i--]);
    printf("\n");
}

int     main(int argc, char **argv)
{
    int i;
    int j;
    t_stack a;
    t_stack b;
    
    i = 0;
    j = 0;
    a.data = malloc(sizeof(int)*argc);
    b.data = malloc(sizeof(int)*argc);
    a.top = -1;
    b.top = -1;
    while (++i < argc)
        push(&a, atoi(argv[argc - i]));
    while (++j < argc)
        push(&b, atoi(argv[argc - j])+4);
    sa(&a);
    ra(&a);
    display(a);
    //display(b);
    return (0);
}