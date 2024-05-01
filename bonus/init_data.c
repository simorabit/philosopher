#include "philo_bonus.h"

char *get_sem_name(int id)
{
    return (ft_strjoin("/sem_philo_", ft_itoa(id)));
}
void init_philo(t_table *table, int id)
{
    t_philo philo;
    
    philo = table->philo;
    philo.meals_eaten = 0;
    philo.isfull = 0;
    philo.sem_philo = sem_open(get_sem_name(id), O_CREAT | O_EXCL, 0644, 1);
    set_long(philo.sem_philo, &philo.last_meal_time, gettime());
    philo.table = table;
}


void init_data(t_table *table)
{
    table->s_sem_fork = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->philos);
    table->s_table = sem_open("/sem_table", O_CREAT | O_EXCL, 0644, 1);
    table->end_dinner = 0;
    table->start_dinner = 0;
}