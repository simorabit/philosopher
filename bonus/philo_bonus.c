/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:46:24 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/03 11:51:46 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

// void clean_up(t_table *table)
// {
	
// }
int main(int argc, char *arv[])
{
	t_table table;

	if (argc != 5 && argc != 6)
		error_exit("Error in inputs");
	read_input(&table, arv);
	init_data(&table);
	create_processes(&table);
	// clean_up(&table);
}
