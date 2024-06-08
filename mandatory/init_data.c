/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:53:45 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/08 12:54:23 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;
	int		philo_nbr;

	philo_nbr = table->philos;
	i = 0;
	while (i < philo_nbr)
	{
		philo = table->philos_list + i;
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->isfull = 0;
		pthread_mutex_init(&philo->m_last_meal_time, NULL);
		pthread_mutex_init(&philo->m_isfull, NULL);
		set_long(&philo->m_last_meal_time, &philo->last_meal_time, gettime());
		philo->left_fork = &table->forks[philo->id - 1];
		philo->right_fork = &table->forks[philo->id % philo_nbr];
		philo->table = table;
		i++;
	}
}

void	init_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->m_enddinner, NULL);
	pthread_mutex_init(&table->m_start_dinner, NULL);
	table->end_dinner = 0;
	table->start_dinner = 0;
}

int	init_data(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos);
	if (!table->forks)
		return (error_exit("Error in allocation"), -1);
	table->philos_list = malloc(sizeof(t_philo) * table->philos);
	if (!table->philos_list)
		return (error_exit("Error in allocation"), -1);
	init_table(table);
	init_philo(table);
	return 0;
}
