#include "philo.h"
long gettime()
{
    struct timeval tv;
    
    if(gettimeofday(&tv, NULL))
        perror("error in gettime");
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
bool dinner_end(t_table *table)
{
    return get_bool(&table->m_enddinner, &table->end_dinner);
}
void display_msg(t_philo *philo, t_state state)
{
    long time = gettime() - philo->table->start_dinner;
    if(philo->isfull)
        return ;
    if(state == Eating && !dinner_end(philo->table))
        printf("%ld %d is eating\n", time, philo->id);
    else if(state == Sleeping && !dinner_end(philo->table))
        printf("%ld %d is sleeping\n", time, philo->id);
    else if(state == Thinking && !dinner_end(philo->table))
        printf("%ld %d is thinking\n", time, philo->id);
    else if(state == Died)
        printf("%ld %d died\n", time, philo->id);
    else if(state == TakenFork && !dinner_end(philo->table))
        printf("%ld %d has taken a fork\n", time, philo->id);
}
int is_philos_full(t_table *table)
{
    int i;

    i = 0;
    while (i < table->philos)
    {
        if(!table->philos_list[i].isfull)
        {
            return 0;
        }
        i++;    
    }
    return 1;
}
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = gettime();
	while ((gettime() - start) < milliseconds)
		usleep(500);
	return (0);
}