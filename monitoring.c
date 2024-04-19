#include "philo.h"
int philo_die(t_philo *philo)
{
    long time;

    time = gettime() - get_long(&philo->table->m_start_dinner, &philo->table->start_dinner);
    if(time > philo->table->time_to_die)
        return 1;
    return 0;
}
int check_philo_dies(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        if(philo_die(&table->philos_list[i]))
        {
            display_msg(&table->philos_list[i], Died);
            set_bool(&table->m_enddinner, &table->end_dinner, 1);
            return 1;
        }
        i++;
    }
    
    return 0;
}

void *monitoring(void *table)
{
    t_table *m_table;

    m_table = (t_table*)table;
    while(1)
    {
        if(check_philo_dies(m_table))
            break;
    }
    return (NULL);
}
void destroy_all(t_table *table)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&table->m_enddinner);
    while (i < table->philos)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
}
// table