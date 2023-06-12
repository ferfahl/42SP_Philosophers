/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:15 by feralves          #+#    #+#             */
/*   Updated: 2023/06/12 19:06:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_forks	*init_forks(t_init *init)
{
	t_forks	*forks;
	int		i;
	
	i = 0;
	forks = malloc(sizeof(t_forks) * init->nbr_of_philos);
	if (!forks)
		return (NULL);
	while (i < init->nbr_of_philos)
	{
		forks[i].has_fork = TRUE;
		pthread_mutex_init(&forks[i].fork, NULL);
		i++;
	}
	return (forks);
}

static int	check_forks(int i, int nbr, int check)
{
	int j;

	j = ((i + 1) % nbr);
	if (check == 0)
	{
		if (i < j)
			return (i);
		return (j);
	}
	else if (check == 1)
	{
		if (i > j)
			return (i);
		return (j);
	}
	return (0);
}

t_philos	*init_philos(t_init *init, t_forks *forks)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philos) * init->nbr_of_philos);
	if (!philos)
		return (NULL);
	while (i < init->nbr_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].init = init;
		philos[i].left_fork = \
			&forks[check_forks(i, init->nbr_of_philos, 0)].fork;
		philos[i].right_fork = \
			&forks[check_forks(i, init->nbr_of_philos, 1)].fork;
		i++;
	}
	return (philos);
}
