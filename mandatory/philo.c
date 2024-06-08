/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:12:26 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/08 13:09:53 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *philo)
{
	t_philo mphilo;

	mphilo = *(t_philo *)philo;
	while (!get_long(&mphilo.table->m_start_dinner, &mphilo.table->start_dinner));
	if (mphilo.id % 2 == 0)
		ft_usleep(mphilo.table->time_to_eat);
	while (!dinner_end(mphilo.table) && !mphilo.isfull)
	{
		if (mphilo.table->philos == 1)
			return (display_msg(&mphilo, DIED), NULL);
		eat(philo);
		display_msg(&mphilo, SLEEPING);
		ft_usleep(mphilo.table->time_to_sleep);
		display_msg(&mphilo, THINKING);
	}
	return (NULL);
}

void threads_creation(t_table *table)
{
	int i;

	i = 0;
	while (i < table->philos)
	{
		if (pthread_create(&(table)->philos_list[i].id_thread, NULL,
						   routine, &(table)->philos_list[i]) != 0)
			return ;
		i++;
	}
	if (pthread_create(&table->observer, NULL, monitoring, table) != 0)
		return ;
	set_long(&table->m_start_dinner, &table->start_dinner, gettime());
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
// void cc()
// {
// 	system("leaks philo");
// }
int main(int argc, char *arv[])
{
	t_table table;
	// atexit(cc);
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
	if(init_data(&table) == -1)
		return (0);
	threads_creation(&table);
	destroy_all(&table);
	return (0);
}
