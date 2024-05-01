/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:00 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/01 13:40:16 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

int philo_die(t_table *table)
{
    long time;
    sem_wait(table->s_table);
    time = gettime() - get_long(table->philo.sem_philo, &table->philo.last_meal_time);
    sem_post(table->s_table);
    if (time >= table->time_to_die)
        return 1;
    return 0;
}

void *monitoring(void *table)
{
    t_table *mtable;
    mtable = (t_table*)table;
    while(1)
    {
        if(philo_die(mtable))
        {
            display_msg(mtable->philo, mtable, Died);
            exit(exit_id);
        }
    }
    return (NULL);
}
// void destroy_all(t_table *table)
// {
//     int i;

//     i = 0;
//     sem_close(table->s_table);
//     sem_close(table->s_sem_fork);
//     while (i < table->philos)
//     {
//         sem_close(table->philo);
//         i++;
//     }
//     i = 0;
//     // free(&table->philos_list[0]);
//     // while (i < table->philos)
//     // {
//     //     free(&table->philos_list[i]);
//     //     i++;
//     // }
//     // free(&table->philos_list);
//     exit(0);
// }
