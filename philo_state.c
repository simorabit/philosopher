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
    ft_usleep(table->time_to_eat);
    if(is_philos_full(table))
        set_bool(&table->m_enddinner, &table->end_dinner, 1);
    philo->meals_eaten++;
    if(philo->meals_eaten == table->meals_must_eate)
        philo->isfull = 1;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}