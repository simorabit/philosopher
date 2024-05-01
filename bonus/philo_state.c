#include "philo_bonus.h"

void eat(t_table *table)
{
    sem_wait(table->s_sem_fork);
    display_msg(table->philo,table, TakenFork);
    sem_wait(table->s_sem_fork);
    display_msg(table->philo,table, TakenFork);
    display_msg(table->philo, table, Eating);

    set_long(table->philo.sem_philo, &table->philo.last_meal_time, gettime());
    // if (is_philos_full(table))
    //     set_bool(table->s_table, &table->end_dinner, 1);
    table->philo.meals_eaten++;
    if (table->philo.meals_eaten == table->meals_must_eate)
        set_bool(table->philo.sem_philo, &table->philo.isfull, 1);
    ft_usleep(table->time_to_eat);
    sem_post(table->s_sem_fork);
    sem_post(table->s_sem_fork);
}
