/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:00:34 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/06 15:09:48 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free(t_sort *tab)
{
	if (tab->str)
		free(tab->str);
}

void	pushtop_a_tob(t_stack *a, t_stack *b, int top, int *size)
{
	pb(a, b, 1);
	*size = top;
}

void	pushswap(t_stack *a, t_stack *b, int argc)
{
	t_sort	tab;

	if (ifisorted(a))
		return ;
	tab = sort(*a);
	if (argc <= 6)
		randomsort(a, b, argc - 1);
	else if (argc > 6 && argc < 102)
	{
		pushatob(tab, a, b);
		pushbtoa(a, b, 1);
		pushbtoa(a, b, 0);
	}
	else
	{
		chunkmetod(tab, a, b);
		push_max_toa(a, b);
	}
	ft_free(&tab);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	i = 0;
	j = 0;
	a.data = malloc(sizeof(int) * argc);
	b.data = malloc(sizeof(int) * argc);
	a.top = -1;
	b.top = -1;
	while (++i < argc)
	{
		if (!ft_isdigit(argv[argc - i]))
			return (ft_perror("Eroor\n"));
		push(&a, ft_atoi(argv[argc - i]));
	}
	ifisduplicate(a);
	pushswap(&a, &b, argc);
	free(a.data);
	free(b.data);
	return (0);
}
