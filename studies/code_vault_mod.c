/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_vault_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:49:39 by feralves          #+#    #+#             */
/*   Updated: 2023/06/01 16:49:40 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define TH_SIZE 8
int mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	th[TH_SIZE];
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < TH_SIZE; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL))
		{
			perror("Failed to create thread\n");
			return (1);
		}
		printf("Thread %d has started\n", i);
	}
	for (i = 0; i < TH_SIZE; i++)
	{
		if (pthread_join(th[i], NULL))
		{
			perror("Failed to join thread\n");
			return (1);	
		}
		printf("Thread %d has finished\n", i);			
	}
	printf("Number of mails: %d\n\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}