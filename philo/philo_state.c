/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:26:37 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 14:09:48 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(philo->right_fork);
	display_msg(philo, TAKEN_FORK);
	pthread_mutex_lock(philo->left_fork);
	display_msg(philo, TAKEN_FORK);
	display_msg(philo, EATING);
	set_long(&philo->m_last_meal_time, &philo->last_meal_time, gettime());
	if (is_philos_full(table))
		set_bool(&table->m_enddinner, &table->end_dinner, 1);
	philo->meals_eaten++;
	if (philo->meals_eaten == table->meals_must_eate)
		set_bool(&philo->m_isfull, &philo->isfull, 1);
	ft_usleep(table, table->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
