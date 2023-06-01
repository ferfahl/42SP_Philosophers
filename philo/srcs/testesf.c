#include "philo.h"

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
