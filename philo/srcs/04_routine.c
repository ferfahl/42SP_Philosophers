/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:29 by feralves          #+#    #+#             */
/*   Updated: 2023/06/12 19:32:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_everyone_alive(t_init *init)
{
	pthread_mutex_lock(&init->death);
	if (init->someone_died == TRUE)
	{
		pthread_mutex_unlock(&init->death);
		return (TRUE);
	}
	pthread_mutex_unlock(&init->death);
	return (FALSE);
}

int	eating(t_init *init, t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_everyone_alive(init))
		return (1);
	print_status(philo, "has taken a fork");
	if (philo->init->nbr_of_philos == 1)
	{
		usleep(philo->init->time_to_die);
		pthread_mutex_lock(&philo->init->death);
		init->someone_died = TRUE;
		pthread_mutex_unlock(&philo->init->death);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->init->m_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->init->m_last_meal);
	pthread_mutex_lock(&init->stop_dinner);
	philo->meals_eaten++;
	pthread_mutex_unlock(&init->stop_dinner);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	usleep(philo->init->time_eating * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

void	sleeping(t_init *init, t_philos *philo)
{
	if (is_everyone_alive(init))
		return ;
	print_status(philo, "is sleeping");
	usleep(init->time_sleeping * 1000);
}

void	thinking(t_init *init, t_philos *philo)
{
	if (is_everyone_alive(init))
		return ;
	print_status(philo, "is thinking");
}

void	*routine(void *philo_action)
{
	t_philos	*p;
	t_init		*init;

	p = (t_philos *)philo_action;
	init = p[0].init;
	if (!(p->id % 2))
		usleep(10000);
	while (!is_everyone_alive(init))
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
