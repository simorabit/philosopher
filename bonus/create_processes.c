/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:39:54 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/24 17:58:05 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void create_processes(t_table *table)
{
	int i;
	int pid;

	i = 0;
	table->start_dinner = gettime();
	while (i < table->philos)
	{
		pid = fork();
		if(pid == 0) 
		{
			routine(table, i);
			exit(0);
		}
		else if (pid < 0)
			error_exit("Error in fork");
		table->philos_list[i] = pid;
		i++;
	}
	wait_process(table);
}

void wait_process(t_table *table)
{
    int status;
    int i;

    i = 0;
    status = 0;
	while (1)
	{
		if (waitpid(-1, &status, WNOHANG) == -1)
			break ;
		if(WEXITSTATUS(status) == exit_id)
		{
			i = 0;
			while (i < table->philos)
			{
				kill(table->philos_list[i], SIGQUIT);
				i++;
			}
			break;
		}
	}
}