/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:28:12 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/27 13:58:23 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
    int id;
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_eat;
}   t_philo;

pthread_t *create_threads(t_philo *philo);
int ft_atoi(const char *str);
int ft_isdigit(int c);
int ft_strlen(char *str);
int ft_error(char *str);

#endif