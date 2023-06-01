#include "../include/philo.h"

void	print_test(t_init *init)
{
	int	index;

	index = 0;
	// (void)init;
	// printf("Teste\n");
	printf("number_of_philosophers: %d\n", init->nbr_of_philos);
	printf("time_to_die: %d\n", init->time_to_die);
	printf("time_to_eat: %d\n", init->time_eating);
	printf("time_to_sleep: %d\n", init->time_sleeping);
	printf("number_of_times_each_philosopher_must_eat: %d\n", init->nbr_of_times_to_eat);
	free(init);
}

//number_of_philosophers 
//time_to_die 
//time_to_eat 
//time_to_sleep 
//[number_of_times_each_philosopher_must_eat]
int	main(int argc, char *argv[])
{
	t_init	*init;

	init = NULL;
	if (!arguments_validation(argc, argv, &init))
		return (-1);
	print_test(init);
	//iniciar threads
	return (0);
}