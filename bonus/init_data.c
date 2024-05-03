#include "philo_bonus.h"

char *get_sem_name(int id)
{
    return (ft_strjoin("/philo_", ft_itoa(id)));
}
void init_philo(t_philo *philo, int id)
{
    philo->meals_eaten = 0;
    philo->id = id;
    philo->isfull = 0;
    philo->sem_philo = sem_open(get_sem_name(id), O_CREAT | O_EXCL, 0644, 1);
    set_long(philo->sem_philo, &philo->last_meal_time, gettime());
}

void init_data(t_table *table)
{
    sem_unlink("/sem_table");
    sem_unlink("/forks");
    table->s_sem_fork = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->philos);
    table->s_print = sem_open("/sem_print", O_CREAT | O_EXCL, 0644, 1);
    table->philos_list = malloc(table->philos * sizeof(int));
    if (!table->philos_list)
		error_exit("ERROR");
    table->end_dinner = 0;
    table->start_dinner = 0;
}