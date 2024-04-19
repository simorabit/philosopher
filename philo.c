#include "philo.h"

void *routine(void *philo)
{
    t_philo phil = *(t_philo *)philo;
    while (!dinner_end(phil.table))
    {
        if(phil.isfull)
            break;
        if(phil.table->philos == 1)
            return (display_msg(&phil, Died), NULL);
        eat(philo);
        display_msg(philo, Sleeping);
        ft_usleep(phil.table->time_to_sleep);
        display_msg(philo, Thinking);
    }
    return (NULL);
}

void thread_work(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        pthread_create(&(table)->philos_list[i].id_thread, NULL, routine, &(table)->philos_list[i]);
        i++;
    }
    set_long(&table->m_start_dinner, &table->start_dinner, gettime());
    pthread_create(&table->observer, NULL, monitoring, table);
    i = 0;
    while (i < table->philos)
    {
        pthread_join(table->philos_list[i].id_thread, NULL);
        i++;
    }
    pthread_join(table->observer, NULL);
    destroy_all(table);
}
int main(int argc, char *arv[])
{
    t_table table;

    if (argc != 5 && argc != 6)
        error_exit("error in inputs");
    read_input(&table, arv);
    init_data(&table);
    thread_work(&table);
}