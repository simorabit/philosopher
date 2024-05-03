#include "philo_bonus.h"

char *get_sem_name(int id)
{
    return (ft_strjoin("/philo_", ft_itoa(id)));
}
void init_philo(t_philo *philo, int id)
{
    char    *sem_name;
    sem_name = get_sem_name(id);
    if(!sem_name)
        error_exit("error in allocation");
    // sem_unlink(sem_name);
    philo->sem_philo = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
    free(sem_name);
    philo->meals_eaten = 0;
    philo->id = id;
    philo->isfull = 0;
    set_long(philo->sem_philo, &philo->last_meal_time, gettime());
}

void init_data(t_table *table)
{
    sem_unlink(sem_print);
    sem_unlink(sem_forks);
    table->s_sem_fork = sem_open(sem_forks, O_CREAT | O_EXCL, 0644, table->philos);
    table->s_print = sem_open(sem_print, O_CREAT | O_EXCL, 0644, 1);
    table->philos_list = malloc(table->philos * sizeof(int));
    if (!table->philos_list)
		error_exit("Error in allocation");
    table->end_dinner = 0;
    table->start_dinner = 0;
}