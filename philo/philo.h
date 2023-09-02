/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:19:48 by hbechri           #+#    #+#             */
/*   Updated: 2023/09/02 16:24:22 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				id;
	int				end_eat;
	int				eat_count;
	pthread_t		thread;
	long long		last_eat;
	struct s_philos	*philos;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	dead1;
	pthread_mutex_t	eat;
	pthread_mutex_t	time;
	pthread_mutex_t	end;
	struct s_philos	*philos;
}	t_mutex;

typedef struct s_philos
{
	int			nb_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_eat_max;
	int			end_eating;
	long long	start;
	t_data		*data;
	t_mutex		*mutex;
}	t_philos;

t_mutex		*mutex_struct_init(t_philos *philo);
t_data		*data_struct_init(t_philos *philo);
void		philo_struct_init(t_philos *philo, int ac, char **av);

void		threads_init(t_philos *philos);
void		*routine(void *arg);
void		sleep_time(int t);

int			check_death(t_philos *philos);
int			not_finish_eat(t_data data);

long long	time_ms(void);

int			valid_args(int ac, char **av);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_strlen(char *str);
void		ft_putstr(char *str, int fd);

#endif