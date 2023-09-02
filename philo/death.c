/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:20:30 by hbechri           #+#    #+#             */
/*   Updated: 2023/09/02 16:20:12 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_finish_eat(t_data data)
{
	pthread_mutex_lock(&data.philos->mutex->end);
	if (data.philos->end_eating != 1)
	{
		pthread_mutex_lock(&data.philos->mutex->print);
		printf ("%lld philo %d %s\n",
			(time_ms() - data.philos->start), data.id, "died");
		return (0);
	}
	else if (data.philos->end_eating == 1)
		return (0);
	pthread_mutex_unlock(&data.philos->mutex->end);
	return (1);
}

int	check_death(t_philos *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philos->nb_philos)
		{
			pthread_mutex_lock(&philos->mutex->dead);
			pthread_mutex_lock(&philos->mutex->time);
			if (philos->time_to_die <= time_ms() - philos->data[i].last_eat)
			{
				if (!(not_finish_eat(philos->data[i])))
					return (0);
				else if (philos->data[i].end_eat == 1)
					philos->data[i].end_eat++;
				if (philos->data[i].end_eat == philos->nb_philos)
					return (0);
			}
			pthread_mutex_unlock(&philos->mutex->time);
			pthread_mutex_unlock(&philos->mutex->dead);
		}
	}
	return (1);
}
