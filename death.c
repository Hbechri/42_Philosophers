/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:20:30 by hbechri           #+#    #+#             */
/*   Updated: 2023/09/01 00:47:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_finish_eat(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos[i].end_eating != 1)
	{
		pthread_mutex_lock(&data->philos->mutex->print);
		printf ("%lld philo %d %s\n", (time_ms() - data->philos->start), data->id, "died");
		return(0);
	}
	return (1);
}

int	check_death(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->philos->nb_philos)
		{
			pthread_mutex_lock(&data->philos->mutex->dead);
			pthread_mutex_lock(&data->philos->mutex->dead1);
			if (data[i].philos->time_to_die <= time_ms() - data[i].last_eat)
			{
				if (!(not_finish_eat(data)))
					return (0);
				else if (data[i].philos->end_eating == 1)
					data->end_eat++;
				if (data->end_eat == data->philos->nb_philos)
					return (0);
			}
			pthread_mutex_unlock(&data->philos->mutex->dead);
			pthread_mutex_unlock(&data->philos->mutex->dead1);
		}
	}
	return (1);
}
