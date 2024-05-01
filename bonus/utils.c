/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:57:10 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/01 10:31:52 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long gettime()
{
    struct timeval tv;
    
    if (gettimeofday(&tv, NULL))
        error_exit("Error in gettime");
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

bool dinner_end(t_table *table)
{
    return get_bool(table->s_table, &table->end_dinner);
}

void display_msg(t_philo *philo, int state)
{
    long time = gettime() - get_long(philo->table->s_table, &philo->table->start_dinner) ;
    if (philo->isfull)
        return ;
    if (state == Eating && !dinner_end(philo->table))
        printf("%ld %d is eating\n", time, philo->id);
    else if (state == Sleeping && !dinner_end(philo->table))
        printf("%ld %d is sleeping\n", time, philo->id);
    else if (state == Thinking && !dinner_end(philo->table))
        printf("%ld %d is thinking\n", time, philo->id);
    else if(state == Died)
        printf("%ld %d died\n", time, philo->id);
    else if (state == TakenFork && !dinner_end(philo->table))
        printf("%ld %d has taken a fork\n", time, philo->id);
}

int is_philos_full(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        if (!get_bool(table->philo.sem_philo, &table->philo.isfull))
            return 0;
        i++; 
    }
    return 1;
}

void    ft_usleep(long time)
{
    long    milli;

    milli = gettime();
    while (gettime() - milli < time)
        usleep(500);
}
