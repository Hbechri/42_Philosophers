/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:19:16 by hbechri           #+#    #+#             */
/*   Updated: 2023/08/30 15:19:16 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
		{
			ft_putstr("Error: invalid argument\n", 2);
			return (0);
		}
		else if (ft_atoi(av[1]) == 0)
		{
			ft_putstr("Error: it must be at least 2 philosopher\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
