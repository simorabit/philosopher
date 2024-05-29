#include "philo_bonus.h"

void error_exit(char *s)
{
    printf("%s\n", s);
    exit(exit_id);
}

void display_msg(t_table *table , int state)
{
    t_philo *m_philo;

    m_philo = &table->philo;
    long time = gettime() - get_long(m_philo->sem_philo, &table->start_dinner);
    sem_wait(table->s_print);
    if (state == EATING)
        printf("%ld %d is eating\n", time, m_philo->id);
    else if (state == SLEEPING)
        printf("%ld %d is sleeping\n", time, m_philo->id);
    else if (state == THINKING)
        printf("%ld %d is thinking\n", time, m_philo->id);
    else if(state == DIED)
        printf("%ld %d died\n", time, m_philo->id);
    else if (state == TAKEN_FORK)
        printf("%ld %d has taken a fork\n", time, m_philo->id);
    sem_post(table->s_print);
}