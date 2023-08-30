/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:27:49 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/29 18:04:46 by marvin           ###   ########.fr       */
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
            return (ft_error("Malloc error\n"));
        if (valid_args(ac, av) == 0)
            return (0);
        init_philo_struct(philo, ac, av);
    }
    return (0);
}
