#include "../include/philo.h"

void	set_table(t_init *init, t_philos *philos)
{
	int			i;
	// pthread_t	manager;
	pthread_t	*seat;

	i = 0;
	seat = malloc(sizeof(pthread_t) * init->nbr_of_philos);
	while (i < init->nbr_of_philos)
	{
		pthread_create(seat + i, NULL, routine, &philos[i]);
		i++;
	}
	//pthread_create(&manager, NULL, monitor, philos);
	i = 0;
	while (i < init->nbr_of_philos)
	{
		pthread_join(seat[i], NULL);
		i++;
	}
	//pthread_join(manager, NULL);
	free(seat);
}

//[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
//[number_of_times_each_philosopher_must_eat]->opt
int	main(int argc, char *argv[])
{
	t_init		*init;
	t_philos	*philos;
	t_forks		*forks;

	init = NULL;
	if (!arguments_validation(argc, argv, &init))
		return (-1); //function to clean all
	forks = init_forks(init);
	if (!forks)
		return (-1);//function to clean all
	philos = init_philos(init, forks);
	if (!philos)
		return (-1);//function to clean all
	set_table(init, philos);
	//free all
	return (0);
}