/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_vault.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:49:44 by feralves          #+#    #+#             */
/*   Updated: 2023/06/01 16:49:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
	pthread_t	p1, p2, p3, p4;
	pthread_mutex_init(&mutex, NULL);

	printf("Number of mails: %d\n\n", mails);
	if (pthread_create(&p1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&p2, NULL, &routine, NULL))
		return (2);
	if (pthread_create(&p3, NULL, &routine, NULL))
		return (3);
	if (pthread_create(&p4, NULL, &routine, NULL))
		return (4);
	if (pthread_join(p1, NULL))
		return (5);
	if (pthread_join(p2, NULL))
		return (6);
	if (pthread_join(p3, NULL))
		return (7);
	if (pthread_join(p4, NULL))
		return (8);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n\n", mails);
	return (0);
}