#include "philo_bonus.h"

void error_exit(char *s)
{
    printf("%s\n", s);
    exit(1);
}

void display_msg(t_philo philo, t_table *table , int state)
{
    long time = gettime() - get_long(philo.sem_philo, &table->start_dinner);
    sem_wait(table->s_print);
    if (state == Eating)
        printf("%ld %d is eating\n", time, philo.id);
    else if (state == Sleeping)
        printf("%ld %d is sleeping\n", time, philo.id);
    else if (state == Thinking)
        printf("%ld %d is thinking\n", time, philo.id);
    else if(state == Died)
        printf("%ld %d died\n", time, philo.id);
    else if (state == TakenFork)
        printf("%ld %d has taken a fork\n", time, philo.id);
    sem_post(table->s_print);
}