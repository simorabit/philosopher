/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:57:10 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/08 13:01:35 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Error in gettime");
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

bool	dinner_end(t_table *table)
{
	return (get_bool(&table->m_enddinner, &table->end_dinner));
}

void	display_msg(t_philo *philo, int state)
{
	long	time;

	time = gettime() - get_long(&philo->table->m_start_dinner,
			&philo->table->start_dinner);
	if (philo->isfull)
		return ;
	if (state == EATING && !dinner_end(philo->table))
		printf("%ld %d is eating\n", time, philo->id);
	else if (state == SLEEPING && !dinner_end(philo->table))
		printf("%ld %d is sleeping\n", time, philo->id);
	else if (state == THINKING && !dinner_end(philo->table))
		printf("%ld %d is thinking\n", time, philo->id);
	else if (state == DIED)
		printf("%ld %d died\n", time, philo->id);
	else if (state == TAKEN_FORK && !dinner_end(philo->table))
		printf("%ld %d has taken a fork\n", time, philo->id);
}

int	is_philos_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		if (!get_bool(&table->philos_list[i].m_isfull, \
					&table->philos_list[i].isfull))
			return (0);
		i++;
	}
	return (1);
}

void	ft_usleep(long time)
{
	long	milli;

	milli = gettime();
	while (gettime() - milli < time)
		usleep(100);
}
