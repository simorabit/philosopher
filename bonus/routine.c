#include "philo_bonus.h"

void check_if_isfull(t_table *table)
{
    sem_wait(table->philo.sem_philo);
    if (table->philo.meals_eaten == table->meals_must_eate)
        set_bool(table->philo.sem_philo, &table->philo.isfull, 1);
    sem_post(table->philo.sem_philo);
}
void eat(t_table *table)
{
    sem_wait(table->s_sem_fork);
    display_msg(table, TAKEN_FORK);
    sem_wait(table->s_sem_fork);
    display_msg(table, TAKEN_FORK);
    display_msg(table, EATING);
    set_long(table->philo.sem_philo, &table->philo.last_meal_time, gettime());
    increment_int(table->philo.sem_philo, &table->philo.meals_eaten);
    check_if_isfull(table);
    ft_usleep(table->time_to_eat);
    sem_post(table->s_sem_fork);
    sem_post(table->s_sem_fork);
}
void routine(t_table *table, int id)
{
	init_philo(&table->philo, id);
	wait_even_process(table, id);
	if (pthread_create(&table->observer, NULL, &monitoring, 
			table) == -1)
		error_exit("Error in Thread");	
	pthread_detach(table->observer);		
	while (1) 
	{
		if(table->philo.isfull)
			exit(0);
		eat(table);
		display_msg(table, SLEEPING);
		ft_usleep(table->time_to_sleep);
		display_msg(table, THINKING);
	}
    sem_close(table->philo.sem_philo);
}

