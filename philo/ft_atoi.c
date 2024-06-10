/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:59:46 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 14:34:20 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isnumber(const char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		if (!(num[++i] >= '0' && num[i] <= '9'))
			return (0);
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (!isnumber(str))
		return (-1);
	while ((*str && *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(sign *= -1);
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (-1);
		str++;
	}
	return (result * sign);
}
