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

//structs

typedef struct	s_init
{
	int			nbr_of_philos;
	int			time_to_die;
	int			time_eating;
	int			time_sleeping;
	int			nbr_of_times_to_eat;
}				t_init;

typedef struct	s_philos
{
	int			id;
	int			value;
	
}
//libft_funct.c
int			ft_strlen(char *str);
int			ft_isdigit(int c);
long int	ft_atoi_mod(char *nptr);

//02_validate_input.c
int			arguments_validation(int argc, char *argv[], t_init **init);


#endif