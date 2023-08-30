/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:51:20 by marvin            #+#    #+#             */
/*   Updated: 2023/08/29 16:51:20 by marvin           ###   ########.fr       */
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
			ft_putstr("Error: it must be at least 1 philosopher\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}