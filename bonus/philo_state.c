#include "philo_bonus.h"

void eat(t_table *table)
{
    t_philo philo;

    philo = table->philo;
    sem_wait(table->s_sem_fork);
    display_msg(&philo, TakenFork);
    sem_wait(table->s_sem_fork);
    display_msg(&philo, TakenFork);
    display_msg(&philo, Eating);
    set_long(philo.sem_philo, &philo.last_meal_time, gettime());
    if (is_philos_full(table))
        set_bool(table->s_table, &table->end_dinner, 1);
    philo.meals_eaten++;
    if (philo.meals_eaten == table->meals_must_eate)
        set_bool(philo.sem_philo, &philo.isfull, 1);
    ft_usleep(table->time_to_eat);
    sem_post(table->s_sem_fork);
    sem_post(table->s_sem_fork);
}