/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:41:06 by feralves          #+#    #+#             */
/*   Updated: 2023/06/13 10:31:59 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_stuffed(t_init *init, t_philos *p)
{
	int	boolean;

	boolean = FALSE;
	pthread_mutex_lock(&init->stop_dinner);
	if (p->meals_eaten == init->nbr_of_times_to_eat)
		boolean = TRUE;
	pthread_mutex_unlock(&init->stop_dinner);
	return (boolean);
}

static int	died_of_starvation(t_philos *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->init->m_last_meal);
	last_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->init->m_last_meal);
	if (last_meal > philo->init->time_to_die)
		return (TRUE);
	return (FALSE);
}

static void	raise_stop_dinner(t_init *init)
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
	while (!is_stuffed(init, philo))
	{
		count = 0;
		while (count < init->nbr_of_philos)
		{
			if (died_of_starvation(&philo[count]))
			{
				raise_stop_dinner(init);
				print_status(&philo[count], "is dead");
				return (NULL);
			}
			count++;
		}
		usleep(3000);
	}
	return (NULL);
}
