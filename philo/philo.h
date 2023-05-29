/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:34:47 by feralves          #+#    #+#             */
/*   Updated: 2023/05/29 18:57:11 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> //memset
# include <stdio.h> //printf
# include <stdlib.h> //malloc / free
# include <unistd.h> //unistd usleep
# include <sys/time.h> //gettimeofday
# include <pthread.h> //phthread_create / pthread_detach 
// pthread_join / pthread_mutex_init / pthread_mutex_destroy 
// pthread_mutex_lock / pthread_mutex_unlock


//libft_funct.c
int	ft_strlen(char *str);


#endif