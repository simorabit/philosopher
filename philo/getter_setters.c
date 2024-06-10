/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:51 by mal-mora          #+#    #+#             */
/*   Updated: 2024/05/19 17:53:24 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	var;

	pthread_mutex_lock(mutex);
	var = *value;
	pthread_mutex_unlock(mutex);
	return (var);
}

int	get_bool(pthread_mutex_t *mutex, int *value)
{
	int	var;

	pthread_mutex_lock(mutex);
	var = *value;
	pthread_mutex_unlock(mutex);
	return (var);
}

void	set_bool(pthread_mutex_t *mutex, int *dest, int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}
