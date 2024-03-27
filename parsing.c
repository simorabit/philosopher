#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
    write(fd, "\n", 1);
}

void error_exit(char *s)
{
    ft_putstr_fd(s, 1);
    exit(1);
}
void read_input(t_table *table, char *arv[])
{
    table->philos = ft_atoi(arv[1]);
    table->time_to_die = ft_atoi(arv[2]);
    table->time_to_eat = ft_atoi(arv[3]);
    table->time_to_sleep = ft_atoi(arv[4]);
    if(arv[5])
        table->meals = ft_atoi(arv[5]);
}