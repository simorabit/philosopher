#include "philo_bonus.h"

char *get_sem_name(int id)
{
    return (ft_strjoin("/sem_philo_", ft_itoa(id)));
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
    table->s_sem_fork = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->philos);
    table->s_table = sem_open("/sem_table", O_CREAT | O_EXCL, 0644, 1);
    table->end_dinner = 0;
    table->start_dinner = 0;
}