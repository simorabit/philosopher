#include "philo.h"

void *routine(void *philo)
{
    t_philo mphilo;
    
    mphilo = *(t_philo *)philo;
    while (!get_long(&mphilo.table->m_start_dinner, &mphilo.table->start_dinner));
    if (mphilo.id % 2 == 0)
        ft_usleep(mphilo.table->time_to_eat);
    while (!dinner_end(mphilo.table) && !mphilo.isfull)
    {
        if (mphilo.table->philos == 1)
            return (display_msg(&mphilo, Died), NULL);
        eat(philo);
        display_msg(&mphilo, Sleeping);
        ft_usleep(mphilo.table->time_to_sleep);
        display_msg(&mphilo, Thinking);
    }
    return (NULL);
}

void threads_creation(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        if (pthread_create(&(table)->philos_list[i].id_thread, NULL, 
                routine, &(table)->philos_list[i]) != 0)
            destroy_all(table);
        i++;
    }
    if (pthread_create(&table->observer, NULL, monitoring, table) != 0)
        destroy_all(table);
    set_long(&table->m_start_dinner, &table->start_dinner, gettime());
    i = 0;
    while (i < table->philos)
    {
        if (pthread_join(table->philos_list[i].id_thread, NULL) != 0)
            destroy_all(table);
        i++;
    }
    if (pthread_join(table->observer, NULL) != 0)
        destroy_all(table);
}

void    leaks(void)
{
    system("leaks philo");
}

int main(int argc, char *arv[])
{
    t_table table;

    atexit(leaks);
    if (argc != 5 && argc != 6)
        error_exit("Error in inputs");
    read_input(&table, arv);
    init_data(&table);
    threads_creation(&table);
    destroy_all(&table);
}