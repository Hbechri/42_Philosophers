/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:58:56 by marvin            #+#    #+#             */
/*   Updated: 2023/08/29 16:58:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*mutex_struct_init(t_philos *philo)
{
	t_mutex	*mutex;
	int		i;

	i = 0;
	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (NULL);
	mutex->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->nb_philos);
	if (!mutex->forks)
		return (NULL);
	while (i < philo->nb_philos)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->dead, NULL);
	pthread_mutex_init(&mutex->eat, NULL);
	pthread_mutex_init(&mutex->time, NULL);
	pthread_mutex_init(&mutex->end, NULL);
	mutex->philo = philo;
	return (mutex);
}

t_data	data_struct_init(t_philos *philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo->data;
	data = (t_data *)malloc(sizeof(t_data) * philo->nb_philos);
	if (!philo->data)
		return (NULL);
	while (i < philo->nb_philos)
	{
		philo->data[i].id = i + 1;
		philo->data[i].end_eat = 0;
		philo->data[i].eat_count = 0;
		philo->data[i].last_eat = time_ms();
		philo->data[i].philo = philo;
		i++;
	}
	return (data);
}

void	philo_struct_init(t_philo *philos, int ac, char **av)
{
	philo->nb_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
		philo->nb_eat_max = ft_atoi(av[5]);
	else
		philo->nb_eat_max = -1
	philo->start = time_ms();

	philo->data = data_struct_init(philo);
	philo->mutex = mutex_struct_init(philo);
}