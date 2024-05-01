
#include "philo_bonus.h"
void routine(t_table *table, int id)
{
    init_philo(table, id);
    if(id % 2 == 0)
        ft_usleep(table->time_to_eat);
    if (pthread_create(&table->observer, NULL, &monitoring, 
            table) == -1)
            error_exit("ERROR");
    while (1) 
    {
        eat(table);
        display_msg(&table->philo, Sleeping);
        ft_usleep(table->time_to_sleep);
        display_msg(&table->philo, Thinking);
    }
    pthread_join(table->observer, NULL);
}

void create_processes(t_table *table)
{
    int i;
    int pid = 0;

    i = 0;
    set_long(table->s_table, &table->start_dinner, gettime());
    table->philos_list = malloc(table->philos * sizeof(int));
    if (!table->philos_list)
        error_exit("ERROR");
    while (i < table->philos)
    {
        pid = fork();
        if(pid == 0) // child part
        {
            routine(table, i);
            exit(1);
        }
        else if (pid < 0)
            error_exit("ERROR");
        else
            table->philos_list[i] = pid;
        i++;
    }
    int status  = 0;
    while (1)
    {
        if (waitpid(-1, &status, WNOHANG) == -1)
            break ;
        if(WEXITSTATUS(status) == exit_id)
        {
            i = 0;
            while (i < table->philos)
            {
                kill(table->philos_list[i], SIGINT);
                i++;
            }
            break;
        }
    }
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