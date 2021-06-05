/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:00:34 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:31:44 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	display(t_stack stack)
{
	int	i;

	i = stack.top;
	while (i >= 0)
		printf("%d ", stack.data[i--]);
	printf("\n");
}

void	pushswap(t_stack *a, t_stack *b, int argc)
{
	if (ifisorted(a))
		exit(0);
	if (argc <= 6)
		randomsort(a, b, argc - 1);
	else if (argc > 6 && argc < 102)
	{
		pushatob(sort(*a), a, b);
		pushbtoa(a, b, 1);
		pushbtoa(a, b, 0);
	}
	else
	{
		chunkmetod(sort(*a), a, b);
		push_max_toa(a, b);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	a;
	t_stack	b;

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
	if (ifisduplicate(a))
	{
		ft_perror("Error\n");
		exit(0);
	}
	pushswap(&a, &b, argc);
	return (0);
}
