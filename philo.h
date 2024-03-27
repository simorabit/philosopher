#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_forks
{
    pthread_mutex_t forks;
    int             id;
}   t_forks;

typedef struct s_philo
{
    int     id;
    pthread_t id_thread;
    int     meals;
    t_forks *left_fork;
    t_forks *right_fork;

}   t_philo;

typedef struct table
{
    int     philos;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meals;
    t_forks *forks;
    t_philo *philos_list;
    bool    philo_die;
}       t_table;

void    read_input(t_table *table, char *arv[]);
void    error_exit(char *s);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);

#endif