/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:20:30 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/30 20:29:53 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_finish_eat(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos[i].end_eating != 1)
	{
		pthread_mutex_lock(&data->mutex->print);
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
			pthread_mutex_lock(&data->mutex->dead);
			// pthread_mutex_lock(&data->philo->died1);
			if (data[i].philos->time_to_die <= time_ms() - data[i].last_eat)
			{
				if (!(not_finish_eat(data)))
					return (0);
				else if (data[i].philos->end_eating == 1)
					data->end_eat++;
				if (data->end_eat == data->philos->nb_philos)
					return (0);
			}
			pthread_mutex_unlock(&data->mutex->dead);
			// pthread_mutex_unlock(&data->philo->died1);
		}
	}
	return (1);
}
