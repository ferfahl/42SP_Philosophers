/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:34:51 by feralves          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	arguments_validation(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (ft_error("Error: Wrong number of arguments.\n"));
	//verificar argv numérico e positivo em todas as casas
	return (0);
}

int	main(int argc, char *argv[])
{
	if (!arguments_validation(argc, argv))
		return (-1);
	//iniciar threads
	return (0);
}