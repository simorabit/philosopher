/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:00 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/01 12:10:23 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

int philo_die(t_philo *philo)
{
    long time;

    time = gettime() - get_long(philo->sem_philo, &philo->last_meal_time);
    if(time >= philo->table->time_to_die)
        return 1;
    return 0;
}

void *monitoring(void *philo)
{
    t_philo *m_philo;
    m_philo = (t_philo*)philo;
    while(1)
    {
        // if(philo_die(m_philo))
        // {
        //     display_msg(*m_philo, m_philo->table, Died);
        //     exit(exit_id);
        // }
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
//         sem_close(table->philos_list[i].sem_philo);
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
