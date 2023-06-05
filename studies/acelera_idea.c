/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acelera_idea.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:49:30 by feralves          #+#    #+#             */
/*   Updated: 2023/06/01 16:49:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
typedef	unsigned long	t_lu;
pthread_mutex_t	mutex;
int count = 0;
t_lu	starttime;

void	print_sleep(int count, int timestamp)
{
	printf("%d Philosopher %d is sleeping\n", timestamp, count);
}

void	print_think(int count, int timestamp)
{
	printf("%d Philosopher %d is thinking\n", timestamp, count);
}

void	print_eat(int count, int timestamp)
{
	printf("%d Philosopher %d is eating\n", timestamp, count);
}

int	timex()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*routine()
{
	t_lu	timestamp;
	t_lu	endtime;

	pthread_mutex_lock(&mutex);
	count++;
	endtime = timex();
	timestamp = (endtime - starttime);
	print_eat(count, timestamp);
	usleep(100000);
	endtime = timex();
	timestamp = (endtime - starttime);
	print_sleep(count, timestamp);
	usleep(200000);
	endtime = timex();
	timestamp = (endtime - starttime);
	print_think(count, timestamp);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t	philo1, philo2, philo3;
	pthread_mutex_init(&mutex, NULL);

	starttime = timex();
	pthread_create(&philo1, NULL, &routine, NULL);
	pthread_create(&philo2, NULL, &routine, NULL);
	pthread_create(&philo3, NULL, &routine, NULL);
	pthread_join(philo1, NULL);
	pthread_join(philo2, NULL);
	pthread_join(philo3, NULL);
	pthread_mutex_destroy(&mutex);
}
