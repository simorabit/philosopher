/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:16:55 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 15:18:21 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	read_input(t_table *table, char *arv[])
{
	table->philos = ft_atoi(arv[1]);
	table->time_to_die = ft_atoi(arv[2]);
	table->time_to_eat = ft_atoi(arv[3]);
	table->time_to_sleep = ft_atoi(arv[4]);
	if (arv[5])
		table->meals_must_eate = ft_atoi(arv[5]);
	else
		table->meals_must_eate = -2;
	if (table->philos <= 0 || table->time_to_die == -1 || \
			table->time_to_eat == -1 || \
			table->time_to_sleep == -1)
		return (-1);
	else if (table->meals_must_eate == -1 || table->meals_must_eate == 0)
		return (-1);
	return (0);
}
