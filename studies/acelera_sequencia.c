/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acelera_sequencia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:49:20 by feralves          #+#    #+#             */
/*   Updated: 2023/06/01 16:49:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h>
#include <stdbool.h>

#define SIZE 5
#define LEFT (i + SIZE - 1) % SIZE
#define RIGHT (i + 1) % SIZE

#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define SLEEPING 3

typedef	unsigned long	t_lu;
t_lu	starttime;

int				state[SIZE];
pthread_t		philos[SIZE];
pthread_mutex_t	mutex;
int				sem[SIZE];

void	print_sleep(t_lu count, int timestamp)
{
	printf("%d Philosopher %ld is sleeping\n", timestamp, count);
}

void	print_think(t_lu count, int timestamp)
{
	printf("%d Philosopher %ld is thinking\n", timestamp, count);
}

void	print_eat(t_lu count, int timestamp)
{
	printf("%d Philosopher %ld is eating\n", timestamp, count);
}

int	timex()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	try_fork(int i)
{
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[i] = EATING;
		printf("Philosopher %ld take forks...\n", (long)i);
	}
	if (sem[i] == 0)
	{
		usleep(100000);
		sem[i] = 1;
	}
}

void	take_forks(int i)
{
	pthread_mutex_lock(&mutex);
	state[i] = HUNGRY;
	try_fork(i);
	pthread_mutex_unlock(&mutex);
}

void	*philosopher(void *n)
{
	long i = (long)n;
	int value = (int) i;
	t_lu endtime;
	t_lu timestamp;

	while (true)
	{
		if (value % 2 == 0)
			usleep(100000);
		take_forks(i);
		endtime = timex();
		timestamp = (endtime - starttime);
		if (state[value] == EATING)
		{
			print_eat(i, timestamp);
			usleep(100000);
			state[value] = SLEEPING;
		}
		if(state[value] == SLEEPING)
		{
			endtime = timex();
			timestamp = (endtime - starttime);
			print_sleep(i, timestamp);
			usleep(200000);
			state[value] = THINKING;
		}
		if (state[value] == THINKING)
		{
			endtime = timex();
			timestamp = (endtime - starttime);
			print_think(i, timestamp);
			usleep(100000);
			state[value] = HUNGRY;
		}
		// put_forks(i);
	}
	return (NULL);
}

int	main(void)
{
	starttime = timex();

	for (long i = 0; i < SIZE; i++)
		pthread_mutex_init(&mutex, NULL);
	for (long i = 0; i < SIZE; i++)
		pthread_create(&philos[i], 0, &philosopher, (void *)i);
	for (long i = 0; i < SIZE; i++)
		pthread_join(philos[i], 0);
}
