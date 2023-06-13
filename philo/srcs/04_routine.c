/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:29 by feralves          #+#    #+#             */
/*   Updated: 2023/06/13 10:36:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_everyone_alive(t_init *init)
{
	pthread_mutex_lock(&init->death);
	if (init->someone_died == TRUE)
	{
		pthread_mutex_unlock(&init->death);
		return (FALSE);
	}
	pthread_mutex_unlock(&init->death);
	return (TRUE);
}

static void	sleeping(t_init *init, t_philos *philo)
{
	if (is_everyone_alive(init))
		print_status(philo, "is sleeping");
	usleep(init->time_sleeping * 1000);
}

static void	thinking(t_init *init, t_philos *philo)
{
	if (is_everyone_alive(init))
		print_status(philo, "is thinking");
}

void	*routine(void *philo_action)
{
	t_philos	*p;
	t_init		*init;

	p = (t_philos *)philo_action;
	init = p[0].init;
	if (!(p->id % 2))
		usleep(5000);
	while (is_everyone_alive(init))
	{
		eating(init, p);
		if (p->meals_eaten == p->init->nbr_of_times_to_eat)
			return (NULL);
		sleeping(init, p);
		thinking(init, p);
		if (p->init->nbr_of_philos % 2)
			usleep(2000);
	}
	return (NULL);
}
