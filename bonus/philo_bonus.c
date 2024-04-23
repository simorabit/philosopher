
#include "philo_bonus.h"
void *routine(void *philo)
{
    t_philo mphilo;
    mphilo = *(t_philo *)philo;
    
    while (!get_long(mphilo.table->s_table, &mphilo.table->start_dinner));
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

void create_processes(t_table *table)
{
    int i;
    int pid = 0;

    i = 0;
    set_long(table->s_table, &table->start_dinner, gettime());
    pid = fork();
    if(pid == 0)
        monitoring(table);
    while (i < table->philos)
    {
        pid = fork();
        if(pid == 0) // child part
        {
            routine(&table->philos_list[i]);
            exit(0);
        }
        else if(pid < 0)
            error_exit("ERROR");
        i++;
    }
    i = 0;
    while (i < table->philos)
    {
        wait(NULL);
        i++;
    }
    wait(NULL);
}

int main(int argc, char *arv[])
{
    t_table table;

    if (argc != 5 && argc != 6)
        error_exit("Error in inputs");
    read_input(&table, arv);
    init_data(&table);
    create_processes(&table);
    // destroy_all(&table);
}