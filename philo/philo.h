/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:01:16 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 16:14:14 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DIED		4

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		id_thread;
	int				id;
	int				meals_eaten;
	int				isfull;
	long			last_meal_time;
	pthread_mutex_t	m_last_meal_time;
	pthread_mutex_t	m_isfull;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philo;

struct s_table
{
	int				philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_must_eate;
	long			s_dinner;
	int				end_dinner;
	pthread_t		observer;
	pthread_mutex_t	m_s_dinner;
	pthread_mutex_t	m_enddinner;
	pthread_mutex_t	*forks;
	t_philo			*philos_list;
};

void	error_exit(char *s);
long	ft_atoi(const char *str);
long	gettime(void);
int		get_bool(pthread_mutex_t *mutex, int *value);
bool	dinner_end(t_table *table);
void	display_msg(t_philo *philo, int state);
void	init_philo(t_table *table);
int		init_data(t_table *table);
void	eat(t_philo *philo);
int		is_philos_full(t_table *table);
void	set_bool(pthread_mutex_t *mutex, int *dest, int value);
void	ft_usleep(t_table *table, long time);
void	*monitoring(void *table);
int		destroy_all(t_table *table);
long	get_long(pthread_mutex_t *mutex, long *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
int		read_input(t_table *table, char *arv[]);

#endif
