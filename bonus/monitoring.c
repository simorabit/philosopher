/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:00 by mal-mora          #+#    #+#             */
/*   Updated: 2024/04/22 13:58:49 by mal-mora         ###   ########.fr       */
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
int check_philo_dies(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        if(philo_die(&table->philos_list[i]))
        {
            display_msg(&table->philos_list[i], Died);
            set_bool(table->s_table, &table->end_dinner, 1);
            return 1;
        }
        i++;
    }
    return 0;
}

void *monitoring(void *table)
{
    t_table *m_table;

    m_table = (t_table*)table;
    while(1)
    {
        if(check_philo_dies(m_table))
            break;
    }
    return (NULL);
}
void destroy_all(t_table *table)
{
    int i;

    i = 0;
    sem_close(table->s_table);
    sem_close(table->s_sem_fork);
    while (i < table->philos)
    {
        sem_close(table->philos_list[i].sem_philo);
        i++;
    }
    i = 0;
    // free(&table->philos_list[0]);
    // while (i < table->philos)
    // {
    //     free(&table->philos_list[i]);
    //     i++;
    // }
    // free(&table->philos_list);
    exit(0);
}
