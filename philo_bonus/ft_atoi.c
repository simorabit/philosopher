/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:06:03 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 16:07:16 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		error_exit("Input Error");
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
		if ((sign == 1 && result > INT_MAX) \
				|| (sign == -1 && - result < INT_MIN))
			error_exit("Input Error");
		str++;
	}
	return (result * sign);
}
