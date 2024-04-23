#include "philo.h"

void eat(t_philo *philo)
{
    t_table *table;

    table = philo->table;
    pthread_mutex_lock(philo->right_fork);
    display_msg(philo, TakenFork);
    pthread_mutex_lock(philo->left_fork);
    display_msg(philo, TakenFork);
    display_msg(philo, Eating);
    set_long(&philo->m_last_meal_time, &philo->last_meal_time, gettime());
    if (is_philos_full(table))
        set_bool(&table->m_enddinner, &table->end_dinner, 1);
    philo->meals_eaten++;
    if(philo->meals_eaten == table->meals_must_eate)
        set_bool(&philo->m_isfull, &philo->isfull, 1);
    ft_usleep(table->time_to_eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
