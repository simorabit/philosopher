/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:46:24 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/29 14:00:39 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

void clean_up(t_table *table)
{
	free(table->philos_list);
	sem_close(table->s_sem_fork);
	sem_close(table->s_print);
}
// void lllek()
// {
// 	system("leaks philo");
// }
int main(int argc, char *arv[])
{
	t_table table;
	// atexit(lllek);
	if (argc != 5 && argc != 6)
		error_exit("Error in inputs");
	read_input(&table, arv);
	init_data(&table);
	create_processes(&table);
	clean_up(&table);
	// atexit(lllek);
}
