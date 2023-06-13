/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:41:06 by feralves          #+#    #+#             */
/*   Updated: 2023/06/13 11:30:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_full(t_init *init, t_philos *p)
{
	int	check;

	check = FALSE;
	pthread_mutex_lock(&init->stop_dinner);
	if (p->meals_eaten == init->nbr_of_times_to_eat)
		check = TRUE;
	pthread_mutex_unlock(&init->stop_dinner);
	return (check);
}

static int	is_dead(t_philos *philo)
{
	long int	last_meal;

	pthread_mutex_lock(&philo->init->m_last_meal);
	last_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->init->m_last_meal);
	if (last_meal > philo->init->time_to_die)
		return (TRUE);
	return (FALSE);
}

static void	stop_dinner(t_init *init)
{
	pthread_mutex_lock(&init->death);
	init->someone_died = TRUE;
	pthread_mutex_unlock(&init->death);
}

void	*monitor(void *arg)
{
	t_philos	*philo;
	t_init		*init;
	int			count;

	philo = (t_philos *)arg;
	init = philo[0].init;
	while (!is_full(init, philo))
	{
		count = 0;
		while (count < init->nbr_of_philos)
		{
			if (is_dead(&philo[count]))
			{
				stop_dinner(init);
				print_status(&philo[count], "is dead");
				return (NULL);
			}
			count++;
		}
		usleep(5000);
	}
	return (NULL);
}
