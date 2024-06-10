/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:33 by mal-mora          #+#    #+#             */
/*   Updated: 2024/06/09 15:52:41 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_long(sem_t *sem, long *dest, long value)
{
	sem_wait(sem);
	*dest = value;
	sem_post(sem);
}

long	get_long(sem_t *sem, long *value)
{
	long	var;

	sem_wait(sem);
	var = *value;
	sem_post(sem);
	return (var);
}

void	increment_int(sem_t *sem, int *var)
{
	sem_wait(sem);
	(*var)++;
	sem_post(sem);
}

int	get_bool(sem_t *sem, int *value)
{
	int	var;

	sem_wait(sem);
	var = *value;
	sem_post(sem);
	return (var);
}

void	set_bool(sem_t *sem, int *dest, int value)
{
	sem_wait(sem);
	*dest = value;
	sem_post(sem);
}
