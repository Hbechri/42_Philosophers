/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:23:43 by hbechri           #+#    #+#             */
/*   Updated: 2023/09/01 00:12:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_data *data, char *msg)
{
	pthread_mutex_lock(&data->philos->mutex->print);
	printf ("%lld philo %d %s\n", (time_ms() - data->philos->start), data->id, msg);
	pthread_mutex_unlock(&data->philos->mutex->print);
}

void	philos_action(t_data *data)
{
	pthread_mutex_lock(&data->philos->mutex->forks[data->id]);
	print_msg(data, "has taken a fork");
    if(data->id == data->philos->nb_philos)
        pthread_mutex_lock(&data->philos->mutex->forks[0]);
    else
	    pthread_mutex_lock(&data->philos->mutex->forks[data->id + 1]);
	print_msg(data, "has taken a fork");
	print_msg(data, "is eating");
	pthread_mutex_lock(&data->philos->mutex->time); 
	data->last_eat = time_ms();
	pthread_mutex_unlock(&data->philos->mutex->time);
	sleep_time(data->philos->time_to_eat);
	pthread_mutex_unlock(&data->philos->mutex->forks[data->id]);
    if(data->id == data->philos->nb_philos)
        pthread_mutex_unlock(&data->philos->mutex->forks[0]);
    else
	    pthread_mutex_unlock(&data->philos->mutex->forks[data->id + 1]);
}

void	sleep_time(int t)
{
	long long	start;

	start = time_ms();
	usleep(t * 1000 * 0.9); 
	while (time_ms() - start < (long int)t)
		usleep(50);
}

//

void	*routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!(data->id % 2))
		sleep_time(data->philos->time_to_eat); 
	while (1)
	{
		philos_action(data);
		pthread_mutex_lock(&data->philos->mutex->eat);
		data->eat_count++;
		pthread_mutex_unlock(&data->philos->mutex->eat);
		if (data->philos->nb_eat_max != -1 && data->eat_count >= data->philos->nb_eat_max)
		{
			pthread_mutex_lock(&data->philos->mutex->end);
			data->end_eat = 1;
			pthread_mutex_unlock(&data->philos->mutex->end);
			break ;
		}
		print_msg(data, " is sleeping");
		sleep_time(data->philos->time_to_sleep);
		print_msg(data, " is thinking");
	}
	return (NULL);
}

void	threads_init(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->nb_philos)
	{
		pthread_create(&philos->data[i].thread, NULL, &routine, &philos->data[i]);
		pthread_detach(philos->data[i].thread);
		i++;
		usleep(60);
	}
}