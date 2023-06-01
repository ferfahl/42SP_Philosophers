#include "../include/philo.h"

void	init_table(t_philos *philos, t_init *init)

//[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
//[number_of_times_each_philosopher_must_eat]->opt
int	main(int argc, char *argv[])
{
	t_init		*init;
	t_philos	*philos;

	init = NULL;
	if (!arguments_validation(argc, argv, &init))
		return (-1);
	init_table(&philos, init);
	//iniciar threads
	return (0);
}