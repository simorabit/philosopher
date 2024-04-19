#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
typedef struct table t_table;

typedef enum state
{
    TakenFork,
    Eating,
    Sleeping,
    Thinking,
    Died,
} t_state ;

typedef struct s_philo
{
    int             id;
    pthread_t       id_thread;
    int             meals_eaten;
    int             isfull;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_table         *table;
}           t_philo;

struct table
{
    int             philos;
    long            time_to_die;
    long            time_to_eat;
    long            time_to_sleep;
    long            meals_must_eate;
    long            start_dinner;
    pthread_mutex_t m_start_dinner;
    int             end_dinner;
    pthread_mutex_t m_enddinner;
    pthread_t       observer;
    pthread_mutex_t *forks;
    t_philo         *philos_list;
};

void    read_input(t_table *table, char *arv[]);
void    error_exit(char *s);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);
long    gettime();
int     get_bool(pthread_mutex_t *mutex, int *value);
bool    dinner_end(t_table *table);
void    display_msg(t_philo *philo, t_state state);
void    init_philo(t_table *table);
void    init_data(t_table *table);
void    eat(t_philo *philo);
int     is_philos_full(t_table *table);
void    set_bool(pthread_mutex_t *mutex, int *dest, int value);
int     ft_usleep(size_t milliseconds);
void    *monitoring(void *table);
long    get_long(pthread_mutex_t *mutex, long *value);
void    destroy_all(t_table *table);
void    set_long(pthread_mutex_t *mutex, long *dest, long value);
#endif