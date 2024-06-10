/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:46:24 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 14:52:13 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_up(t_table *table)
{
	free(table->philos_list);
	sem_close(table->s_sem_fork);
	sem_close(table->s_print);
}

int	main(int argc, char *arv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		error_exit("Error in inputs");
	if (read_input(&table, arv) == -1)
		error_exit("Input Error");
	init_data(&table);
	create_processes(&table);
	clean_up(&table);
}
