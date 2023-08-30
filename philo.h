/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:28:12 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/29 18:04:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
    int id;
    int end_eat;
    int eat_count;
    pthread_t thread;
    long long last_eat;
    struct s_philos *philos;
}   t_data;

typedef struct s_mutex
{
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t dead;
    pthread_mutex_t eat;
    pthread_mutex_t time;
    pthread_mutex_t end;
    struct s_philos *philos;
}   t_mutex;

typedef struct s_philos
{
    int nb_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_eat_max;
    long long start;
    t_data *data;
    t_mutex *mutex;
}   t_philos;

//pthread_t *create_threads(t_philo *philo);
int ft_atoi(const char *str);
int ft_isdigit(int c);
int ft_strlen(char *str);
int ft_error(char *str);

#endif