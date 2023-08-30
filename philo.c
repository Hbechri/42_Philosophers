/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:20:00 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/30 18:17:53 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos    *philo;
    
    if (ac == 5 || ac == 6)
    {
        philo = malloc(sizeof(t_philos));
        if (!philo)
            return (printf("Malloc error\n"));
        if (valid_args(ac, av) == 0)
            return (0);
        philo_struct_init(philo, ac, av);
        threads_init(philo);
    }
    return (0);
}
