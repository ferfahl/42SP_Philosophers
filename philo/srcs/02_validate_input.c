#include "../include/philo.h"

static int	input_error(char *str)
{
	write(2, "Error:", 6);
	write(2, " ", 1);
	write(2, str, ft_strlen(str));
	ft_putendl_fd("Run: ./philo [nbr_of_philosophers] [time_to_die] "
		"[time_eating] [time_sleeping] "
		"[nbr_of_times_each_philosopher_must_eat]", 2);
	return (FALSE);
}

static void	init_philo(int argc, char *argv[], t_init **init)
{
	(*init) = malloc(sizeof(t_init));
	(*init)->nbr_of_philos = ft_atoi_mod(argv[1]);
	(*init)->time_to_die = ft_atoi_mod(argv[2]);
	(*init)->time_eating = ft_atoi_mod(argv[3]);
	(*init)->time_sleeping = ft_atoi_mod(argv[4]);
	(*init)->nbr_of_times_to_eat = -1;
	if (argc == 6)
		(*init)->nbr_of_times_to_eat = ft_atoi_mod(argv[5]);
	(*init)->start_time = get_time();
	(*init)->someone_died = FALSE;
	pthread_mutex_init(&(*init)->stop_dinner, NULL);
	pthread_mutex_init(&(*init)->death, NULL);
	pthread_mutex_init(&(*init)->print_status, NULL);
}

int	arguments_validation(int argc, char *argv[], t_init **init)
{
	int	index;
	int	argc_i;
	int	number;

	if (argc < 5 || argc > 6)
		return (input_error("Wrong number of arguments.\n"));
	argc_i = argc;
	while (argc_i > 1)
	{
		index = 0;
		while (argv[argc_i - 1][index])
		{
			if (!ft_isdigit(argv[argc_i - 1][index]))
				return (input_error("Arguments must be only intergers.\n"));
			index++;
		}
		number = ft_atoi_mod(argv[argc_i - 1]);
		if (number == 0)
			return (input_error("Interger must be greater than 0.\n"));
		else if (index > 11 || number > INT_MAX)
			return (input_error("Interger must be less than 2147483647.\n"));
		argc_i--;
	}
	init_philo(argc, argv, init);
	return (TRUE);
}
