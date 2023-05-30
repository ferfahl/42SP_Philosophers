/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:26 by feralves          #+#    #+#             */
/*   Updated: 2023/05/30 13:45:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	input_error(char *str)
{
	write(2, "Error:", 6);
	write(2, " ", 1);
	write(2, str, ft_strlen(str));
	printf("Run: ./philo [nbr_of_philosophers] [time_to_die] [time_eating] "
		"[time_sleeping] [nbr_of_times_each_philosopher_must_eat](optional)\n");
	return (FALSE);
}

static void	init_philo(int argc, char *argv[], t_init **init)
{
	(*init) = malloc(sizeof(t_init));
	(*init)->nbr_of_philos = ft_atoi_mod(argv[1]);
	(*init)->time_to_die = ft_atoi_mod(argv[2]);
	(*init)->time_eating = ft_atoi_mod(argv[3]);
	(*init)->time_sleeping = ft_atoi_mod(argv[4]);
	if (argc == 6)
		(*init)->nbr_of_times_to_eat = ft_atoi_mod(argv[5]);
	else
		(*init)->nbr_of_times_to_eat = -1;
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
