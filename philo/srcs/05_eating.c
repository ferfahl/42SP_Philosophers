/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:32:02 by feralves          #+#    #+#             */
/*   Updated: 2023/06/13 10:36:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	only_one(t_init *init, t_philos *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	usleep(philo->init->time_to_die);
	pthread_mutex_lock(&philo->init->death);
	init->someone_died = TRUE;
	return (pthread_mutex_unlock(&philo->init->death));
}

static void	print_eating(t_philos *philo)
{
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	usleep(philo->init->time_eating * 1000);
}

static void	change_stats(t_init *init, t_philos *philo)
{
	pthread_mutex_lock(&init->m_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&init->m_last_meal);
	pthread_mutex_lock(&init->stop_dinner);
	philo->meals_eaten++;
	pthread_mutex_unlock(&init->stop_dinner);
}

int	eating(t_init *init, t_philos *philo)
{
	if (!is_everyone_alive(init))
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (!is_everyone_alive(init))
		return (pthread_mutex_unlock(philo->right_fork));
	print_status(philo, "has taken a fork");
	if (philo->init->nbr_of_philos == 1)
		return (only_one(init, philo));
	pthread_mutex_lock(philo->left_fork);
	change_stats(init, philo);
	if (!is_everyone_alive(init))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (pthread_mutex_unlock(philo->right_fork));
	}
	print_eating(philo);
	pthread_mutex_unlock(philo->left_fork);
	return (pthread_mutex_unlock(philo->right_fork));
}
