
#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>

# define TakenFork	0
# define Eating	    1
# define Sleeping	2
# define Thinking	3
# define Died	    4

#define exit_id 10
# define sem_fork "/semfork";
typedef struct table t_table;

typedef struct s_philo
{
    int     pid;
    int     id;
    int     meals_eaten;
    int     isfull;
    long    last_meal_time;
    sem_t   *sem_philo;
    t_table *table;
}           t_philo;

struct table
{
    int     philos;
    int     *philos_list;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meals_must_eate;
    long    start_dinner;
    int     end_dinner;
    sem_t       *s_table;
    pthread_t   observer;
    sem_t   *s_sem_fork;
    t_philo philo;
};
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void    read_input(t_table *table, char *arv[]);
void    error_exit(char *s);
long	ft_atoi(const char *str);
long    gettime();
int     get_bool(sem_t *sem, int *value);
bool    dinner_end(t_table *table);
void    display_msg(t_philo philo, t_table *table, int state);
void    init_philo(t_philo *philo, int id);
void    increment_int(sem_t *sem, int *var);
void    init_data(t_table *table);
void    eat(t_table *philo);
int     is_philos_full(t_table *table);
void    set_bool(sem_t *sem, int *dest, int value);
void    ft_usleep(long time);
void    *monitoring(void *table);
void    destroy_all(t_table *table);
long    get_long(sem_t *sem, long *value);
void    set_long(sem_t *sem, long *dest, long value);
#endif
