/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:57:10 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 22:37:49 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Error in gettime");
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	dinner_end(t_table *table)
{
	return (get_bool(table->s_print, &table->end_dinner));
}

void	ft_usleep(long time)
{
	long	milli;

	milli = gettime();
	while (gettime() - milli < time)
		usleep(100);
}

void	wait_even_process(t_table *table, int id)
{
	if (id % 2 == 0)
		ft_usleep(table->time_to_eat);
}
