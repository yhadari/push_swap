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

int	ft_perror(char *str)
{
	write(1, str, ft_strlen(str) + 1);
	exit(0);
	return (0);
}

void	display(t_stack stack)
{
	int	i;

	i = stack.top;
	while (i >= 0)
		printf("%d ", stack.data[i--]);
	printf("\n");
}

int	ifisduplicate(t_stack a)
{
	int	size;
	int	index;

	size = a.top;
	while (size >= 0)
	{
		index = size - 1;
		while (index >= 0)
		{
			if (a.data[size] == a.data[index--])
				return (1);
		}
		size--;
	}
	return (0);
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
			return (ft_perror("Eroor\nis not a number\n"));
		push(&a, atoi(argv[argc - i]));
	}
	if (ifisduplicate(a))
	{
		ft_perror("Error\nduplicate\n");
		exit(0);
	}
	pushswap(&a, &b, argc);
	//display(a);
	//display(b);
	return (0);
}
