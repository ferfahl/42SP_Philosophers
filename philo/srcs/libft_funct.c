/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:13:08 by feralves          #+#    #+#             */
/*   Updated: 2023/06/12 14:13:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

long int	ft_atoi_mod(char *nptr)
{
	long int	count;
	long int	result;
	long int	signal;

	signal = 1;
	count = 0;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (count < (int)ft_strlen(nptr) && ft_isdigit(nptr[count]))
	{
		result = result * 10 + (nptr[count] - 48);
		count++;
	}
	return (result * signal);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
