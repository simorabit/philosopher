#include "philo.h"

void init_philo(t_table *table)
{
    int     i;
    t_philo *philo;
    int     philo_nbr;

    philo_nbr = table->philos;
    i = 0;
    while (i < philo_nbr)
    {
        philo = table->philos_list + i;
        philo->id = i + 1;
        philo->meals_eaten = 0;
        philo->isfull = 0;
        philo->left_fork = &table->forks[philo->id - 1];
        philo->right_fork = &table->forks[philo->id % philo_nbr];
        if (philo->id % 2 == 0)
        {
            philo->left_fork = &table->forks[philo->id % philo_nbr];
            philo->right_fork = &table->forks[philo->id - 1];
        }
        philo->table = table;
        i++;
    }
}

void init_var(t_table *table)
{
    pthread_mutex_init(&table->m_enddinner, NULL);
    pthread_mutex_init(&table->m_start_dinner, NULL);
    table->end_dinner = 0;
    table->start_dinner = 0;
}

void init_data(t_table *table)
{
    int i;

    i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->philos);
    if (!table->forks)
        error_exit("Error");
    table->philos_list = malloc(sizeof(t_philo) * table->philos);
    if (!table->philos_list)
        error_exit("Error");
    while (i < table->philos)
    {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
    init_var(table);
    init_philo(table);
}