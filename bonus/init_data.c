#include "philo_bonus.h"

void init_philo(t_table *table)
{
    int i;
    t_philo *philo;
    int philo_nbr;

    philo_nbr = table->philos;
    i = 0;
    while (i < philo_nbr)
    {
        philo = table->philos_list + i;
        philo->id = i + 1;
        philo->meals_eaten = 0;
        philo->isfull = 0;
        philo->sem_philo = sem_open("/sem_philo", O_CREAT | O_EXCL, 0644, 1);
        set_long(philo->sem_philo, &philo->last_meal_time, gettime());
        philo->table = table;
        i++;
    }
}
void init_table(t_table *table)
{
    table->s_sem_fork = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->philos);
    table->s_table = sem_open("/sem_table", O_CREAT | O_EXCL, 0644, table->philos);
    table->end_dinner = 0;
    table->start_dinner = 0;
}

void init_data(t_table *table)
{
    int i;

    i = 0;
    table->philos_list = malloc(sizeof(t_philo) * table->philos);
    if (!table->philos_list)
        error_exit("Error in allocation");
    init_table(table);
    init_philo(table);
}