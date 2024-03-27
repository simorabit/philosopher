#include "philo.h"

void init_data(t_table *table)
{
    int i;

    i = 0;
    table->forks = malloc(sizeof(t_philo) * table->philos);
    if (!table->forks)
        error_exit("Error");
    table->philos_list = malloc(sizeof(t_forks) * table->philos);
    if (!table->philos_list)
        error_exit("Error");
    while (i < table->philos)
    {
        pthread_mutex_init(&(table)->forks[i].forks, NULL);
        table->forks->id = i;
        i++;
    }
    init_philo(table);
}
void *routine(void *philo)
{
    t_philo phil = *(t_philo *)philo;
    // if(phil.id % 2 != 0)
    // {
    //     pthread_mutex_lock()
    // }
    printf("philo %d begain to eat\n", phil.id);
    //sleep(200);
    return (NULL);
}
void thread_work(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        pthread_create(&(table)->philos_list[i].id_thread, NULL, routine, &(table)->philos_list[i]);
        table->philos_list[i].id = i + 1;
        i++;
    }
    i = 0;
    while (i < table->philos)
    {
        pthread_join(table->philos_list[i].id_thread, NULL);
        i++;
    }
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