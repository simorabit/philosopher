/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:28 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 22:37:39 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define SEM_FORK "/sem_forks"
# define SEM_PRINT "/sem_print"

# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DIED		4

# define EXIT_ID	10

typedef struct table	t_table;

typedef struct s_philo
{
	int		id;
	int		meals_eaten;
	int		isfull;
	long	last_meal_time;
	sem_t	*sem_philo;
}	t_philo;

typedef struct table
{
	int			philos;
	int			*philos_list;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meals_must_eate;
	long		start_dinner;
	int			end_dinner;
	sem_t		*s_print;
	pthread_t	observer;
	sem_t		*s_sem_fork;
	t_philo		philo;
}	t_table;

char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	wait_even_process(t_table *table, int id);
void	wait_process(t_table *table);
void	routine(t_table *table, int id);
int		read_input(t_table *table, char *arv[]);
void	error_exit(char *s);
long	ft_atoi(const char *str);
long	gettime(void);
int		get_bool(sem_t *sem, int *value);
int		dinner_end(t_table *table);
void	display_msg(t_table *table, int state);
void	init_philo(t_philo *philo, int id);
void	increment_int(sem_t *sem, int *var);
void	init_data(t_table *table);
void	eat(t_table *philo);
int		is_philos_full(t_table *table);
void	set_bool(sem_t *sem, int *dest, int value);
void	ft_usleep(long time);
void	create_processes(t_table *table);
void	*monitoring(void *table);
void	clean_up(t_table *table);
long	get_long(sem_t *sem, long *value);
void	set_long(sem_t *sem, long *dest, long value);
#endif
