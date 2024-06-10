/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:12:26 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 16:26:13 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	phi;

	phi = *(t_philo *)philo;
	while (!get_long(&phi.table->m_s_dinner, &phi.table->s_dinner))
		;
	if (phi.id % 2 == 0)
		ft_usleep(phi.table, phi.table->time_to_eat);
	while (!dinner_end(phi.table) && !phi.isfull)
	{
		if (phi.table->philos == 1)
			return (display_msg(&phi, DIED), NULL);
		eat(philo);
		display_msg(&phi, SLEEPING);
		ft_usleep(phi.table, phi.table->time_to_sleep);
		display_msg(&phi, THINKING);
	}
	return (NULL);
}

void	threads_creation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		if (pthread_create(&(table)->philos_list[i].id_thread, NULL, \
					routine, &(table)->philos_list[i]) != 0)
			return ;
		i++;
	}
	if (pthread_create(&table->observer, NULL, monitoring, table) != 0)
		return ;
	set_long(&table->m_s_dinner, &table->s_dinner, gettime());
	i = 0;
	while (i < table->philos)
	{
		if (pthread_join(table->philos_list[i].id_thread, NULL) != 0)
			return ;
		i++;
	}
	if (pthread_join(table->observer, NULL) != 0)
		return ;
}

int	main(int argc, char *arv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		error_exit("Error in inputs");
		return (0);
	}
	if (read_input(&table, arv) == -1)
	{
		error_exit("Error in inputs");
		return (0);
	}
	if (init_data(&table) == -1)
		return (0);
	threads_creation(&table);
	destroy_all(&table);
	return (0);
}
