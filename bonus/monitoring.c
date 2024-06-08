/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:00 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/04 17:19:26 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

int philo_die(t_table *table)
{
    long time;
    time = gettime() - get_long(table->philo.sem_philo, &table->philo.last_meal_time);
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
        if (philo_die(mtable))
        {  
            sem_wait(mtable->s_print);
            printf("%ld %d died\n", gettime() - get_long(mtable->philo.sem_philo, \
                &mtable->philo.last_meal_time), mtable->philo.id);
            exit(exit_id);
        }
    }
    return (NULL);
}
// void destroy_all(t_table *table)
// {
//     int i;

//     i = 0;
//     sem_close(table->s_print);
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
