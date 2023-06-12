/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:13:52 by feralves          #+#    #+#             */
/*   Updated: 2023/06/12 20:14:51 by feralves         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647

typedef enum e_doing
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}			t_doing;

//structs

typedef struct s_init
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_eating;
	int				time_sleeping;
	int				nbr_of_times_to_eat;
	int				someone_died;
	int				meals_eaten;
	long int		start_time;
	pthread_mutex_t	stop_dinner;
	pthread_mutex_t	print_status;
	pthread_mutex_t	death;
	pthread_mutex_t	m_last_meal;
	pthread_mutex_t	m_meals_repeated;
}				t_init;

typedef struct s_forks
{
	int				has_fork;
	pthread_mutex_t	fork;
}				t_forks;

typedef struct s_philos
{
	int				id;
	int				value;
	int				meals_eaten;
	long int		last_meal;
	struct s_init	*init;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philos;

//functions

//libft_funct.c
int			ft_strlen(char *str);
int			ft_isdigit(int c);
long int	ft_atoi_mod(char *nptr);
void		ft_putendl_fd(char *s, int fd);

//02_validate_input.c
int			arguments_validation(int argc, char *argv[], t_init **init);

//03_init.c
t_philos	*init_philos(t_init *init, t_forks *forks);
t_forks		*init_forks(t_init *init);

//04_routine.c
void		*routine(void *philo_action);

//05_monitor.c
void		*monitor(void *arg);

//utils
long int	get_time(void);
void		print_status(t_philos *philo, char *status);

#endif