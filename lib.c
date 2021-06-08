/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:13:43 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/06 18:12:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if ((*str <= 47 || *str >= 58) && *str != '-' && *str != '+')
			return (0);
		if ((*str == '-' || *str == '+')
			&& (*(str + 1) > 57 || *(str + 1) < 48))
			return (0);
		str++;
	}
	return (1);
}

void	checkint(char *str, int i)
{
	if (ft_strlen(str) > 11)
		ft_perror("Error\n", 1);
	if (ft_strlen(str) > 10 && str[i] != '-' && str[i] != '+')
		ft_perror("Error\n", 1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	j = 1;
	result = 0;
	checkint(str, i);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result < 0 && j == -1 && result != -2147483648)
		|| (result < 0 && j == 1))
		ft_perror("Error\n", 1);
	return (result * j);
}

int	ft_perror(char *str, int index)
{
	write(1, str, ft_strlen(str) + 1);
	if (index == 1)
		exit(0);
	return (0);
}
