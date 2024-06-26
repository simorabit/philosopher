/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:00 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 16:15:04 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_die(t_philo *philo)
{
	long	time;

	time = gettime() - get_long(&philo->m_last_meal_time,
			&philo->last_meal_time);
	if (time >= philo->table->time_to_die)
		return (1);
	return (0);
}

int	check_philo_dies(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		if (philo_die(&table->philos_list[i]))
		{
			display_msg(&table->philos_list[i], DIED);
			set_bool(&table->m_enddinner, &table->end_dinner, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *table)
{
	t_table	*m_table;

	m_table = (t_table *)table;
	if (m_table->philos == 1)
		return (NULL);
	while (1)
	{
		if (check_philo_dies(m_table))
			break ;
	}
	return (NULL);
}

int	destroy_all(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->m_enddinner);
	pthread_mutex_destroy(&table->m_s_dinner);
	while (i < table->philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos_list[i].m_isfull);
		pthread_mutex_destroy(&table->philos_list[i].m_last_meal_time);
		i++;
	}
	free(table->philos_list);
	free(table->forks);
	error_exit("end of program.");
	return (-1);
}
