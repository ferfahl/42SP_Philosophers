/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:37 by feralves          #+#    #+#             */
/*   Updated: 2023/06/12 14:48:41 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	get_time(void)
{
	struct timeval	time;
	long int		milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milliseconds);
}

void	print_status(t_philos *philo, char *status)
{
	long int	time;
	
	pthread_mutex_lock(&philo->init->print_status);
	time = get_time() - philo->init->start_time;
	printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->init->print_status);
}
