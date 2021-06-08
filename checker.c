/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:03:34 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/04 19:07:07 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	isntoperations(char *bf)
{
	int	size;

	size = ft_strlen(bf);
	if (size == 2)
		if ((bf[0] == 's' && (bf[1] == 'a' || bf[1] == 'b' || bf[1] == 's'))
			|| (bf[0] == 'r' && (bf[1] == 'a' || bf[1] == 'b' || bf[1] == 'r'))
			|| (bf[0] == 'p' && (bf[1] == 'a' || bf[1] == 'b')))
			return (0);
	if (size == 3)
	{
		if ((bf[0] == 'r' && bf[1] == 'r') && (bf[2] == 'a' || bf[2] == 'b'
				|| bf[2] == 'r'))
			return (0);
	}
	return (1);
}

void	checkline(t_stack *a, t_stack *b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		sa(a, 0);
	if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		sb(b, 0);
	if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		ss(a, b, 0);
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		pa(a, b, 0);
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		pb(a, b, 0);
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ra(a, 0);
	if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		rb(b, 0);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		rr(a, b, 0);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a, 0);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b, 0);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b, 0);
}

int	ft_read(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		if (isntoperations(line))
			return (ft_perror("Error\n", 0));
		checkline(a, b, line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	if (ifisorted(a) && b->top == -1)
		return (ft_perror("OK\n", 0));
	else
		return (ft_perror("KO\n", 0));
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
	if (argc == 1)
		return (0);
	while (++i < argc)
	{
		if (!ft_isdigit(argv[argc - i]))
			return (ft_perror("Error\n", 0));
		push(&a, ft_atoi(argv[argc - i]));
	}
	ifisduplicate(a);
	ft_read(&a, &b);
	free(a.data);
	free(b.data);
}
