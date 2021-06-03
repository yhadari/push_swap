/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:13:43 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/03 21:27:55 by yhadari          ###   ########.fr       */
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
