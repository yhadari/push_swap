/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushsoip.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:20:18 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/04 19:03:32 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int			*data;
	int			top;
}				t_stack;

typedef struct s_sort
{
	int			*str;
	int			med;
}				t_sort;

typedef struct s_index
{
	int			top;
	int			zero;
	int			size;
}				t_index;

typedef struct s_info
{
	int			min;
	int			sizemin;
	int			max;
	int			sizemax;
	int			minomax;
	int			size;
}				t_info;

typedef struct s_map
{
	int			chunk;
	int			nb;
}				t_map;

typedef struct s_chunk
{
	int			nb;
	int			size;
	int			index;
	int			size_a;
}				t_chunk;

int		sa(t_stack *stack, int index);
int		sb(t_stack *stack, int index);
int		ss(t_stack *a, t_stack *b, int index);
int		pa(t_stack *a, t_stack *b, int index);
int		pb(t_stack *a, t_stack *b, int index);
int		ra(t_stack *a, int index);
int		rb(t_stack *b, int index);
int		rr(t_stack *a, t_stack *b, int index);
int		rra(t_stack *a, int index);
int		rrb(t_stack *b, int index);
int		rrr(t_stack *a, t_stack *b, int index);
void	push(t_stack *stack, int value);
void	pop(t_stack *stack);
int		peek(t_stack *stack);
int		ft_perror(char *str);
int		abs(int n);
t_sort	sort(t_stack a);
void	pushatob(t_sort tab, t_stack *a, t_stack *b);
void	pushbtoa(t_stack *a, t_stack *b, int c);
int		ifisorted(t_stack *stack);
int		randomsort(t_stack *a, t_stack *b, int size);
void	find_rotate(int size, t_stack *a, t_stack *b, int index);
void	find_rrotate(int size, t_stack *a, t_stack *b, t_sort tab);
void	chunkmetod(t_sort buf, t_stack *a, t_stack *b);
void	push_max_toa(t_stack *a, t_stack *b);
t_info	max_min(t_stack *b);
int		isinchunk(t_map *map, int nb, int chunk, int sizechunk);
void	checkstackb(t_stack *a, t_stack *b, t_info info, int *size);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
int		ft_atoi(const char *str);
int		ifisduplicate(t_stack a);
int		get_next_line(char **line);

#endif
