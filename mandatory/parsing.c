#include "philo.h"

void error_exit(char *s)
{
    printf("%s\n", s);
    // exit(1);
}
void read_input(t_table *table, char *arv[])
{
    table->philos = ft_atoi(arv[1]);
    table->time_to_die = ft_atoi(arv[2]);
    table->time_to_eat = ft_atoi(arv[3]);
    table->time_to_sleep = ft_atoi(arv[4]);
    if(arv[5])
        table->meals_must_eate = ft_atoi(arv[5]);
    else
        table->meals_must_eate = -1;
}