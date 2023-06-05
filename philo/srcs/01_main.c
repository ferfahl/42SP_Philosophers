#include "../include/philo.h"

t_forks	*init_forks(t_init *init)
{
	t_forks	*forks;
	int		i;
	
	i = 0;
	forks = malloc(sizeof(t_forks) * init->nbr_of_philos);
	if (!forks)
		return (NULL);
	while (i < init->nbr_of_philos)
	{
		forks[i].has_fork = TRUE;
		pthread_mutex_init(&forks[i].fork, NULL);
		i++;
	}
	return (forks);
}

int	check_forks(int i, int nbr, int check)
{
	int j;

	j = ((i + 1) % nbr);
	if (check == 0)
	{
		if (i < j)
			return (i);
		return (j);
	}
	else if (check == 1)
	{
		if (i > j)
			return (i);
		return (j);
	}
	return (0);
}

t_philos	*init_philos(t_init *init, t_forks *forks)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philos) * init->nbr_of_philos);
	if (!philos)
		return (NULL);
	while (i < init->nbr_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].init = init;
		philos[i].left_fork = \
			&forks[check_forks(i, init->nbr_of_philos, 0)].fork;
		philos[i].right_fork = \
			&forks[check_forks(i, init->nbr_of_philos, 1)].fork;
		i++;
	}
	return (philos);
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
		return (-1);
	forks = init_forks(init);
	if (!forks)
		return (-1);
	philos = init_philos(init, forks);
	if (!philos)
		return (-1);
	//iniciar threads
	return (0);
}