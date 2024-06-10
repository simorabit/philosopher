/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:15:52 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 16:42:14 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*get_sem_name(int id)
{
	return (ft_strjoin("/philo_", ft_itoa(id)));
}

void	init_philo(t_philo *philo, int id)
{
	char	*sem_name;

	sem_name = get_sem_name(id);
	if (!sem_name)
		error_exit("error in allocation");
	philo->sem_philo = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
	free(sem_name);
	set_bool(philo->sem_philo, &philo->meals_eaten, 0);
	set_bool(philo->sem_philo, &philo->id, id);
	set_bool(philo->sem_philo, &philo->isfull, 0);
	set_long(philo->sem_philo, &philo->last_meal_time, gettime());
}

void	init_data(t_table *table)
{
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORK);
	table->s_sem_fork = sem_open(SEM_FORK, O_CREAT | O_EXCL, 0644, \
			table->philos);
	table->s_print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	table->philos_list = malloc(table->philos * sizeof(int));
	if (!table->philos_list)
		error_exit("Error in allocation");
	table->end_dinner = 0;
	table->start_dinner = 0;
}
