#include "../include/philo.h"

int	verify_death(t_philos *philo)
{
	long int	time;

	time = get_time();
	if (time - philo->last_meal > philo->init->time_to_die)
	{
		//print_status(philo, "died");
		pthread_mutex_lock(&philo->init->death);
		philo->init->someone_died = TRUE;
		pthread_mutex_unlock(&philo->init->death);
		return (1);
	}
	return (0);
}

int	eating(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	//print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	//print_status(philo, "has taken a fork");
	if (verify_death(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	philo->meals_eaten++;
	//print_status(philo, "is eating");
	usleep(philo->init->time_eating); //function to make time right?
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_meal = get_time();
	return (0);
}

void	sleeping(t_philos *philo)
{
	if (verify_death(philo))
		return ;
	//print_status(philo, "is sleeping");
	usleep(philo->init->time_sleeping); //function to make time right?
}

void	thinking(t_philos *philo)
{
	if (verify_death(philo))
		return ;
	//print_status(philo, "is thinking");
	//usleep?
}

void	*routine(void *philo_action)
{
	t_philos	*p;

	p = (t_philos *)philo_action;
	if (!(p->id % 2))
		usleep(10000);
	while (!verify_death(p))
	{
		if (eating(p))
			return (NULL);
		if ((p->init->nbr_of_times_to_eat != -1 && \
			p->meals_eaten == p->init->nbr_of_times_to_eat) || verify_death(p))
			return (NULL);
		sleeping(p);
		thinking(p);
		if (p->init->nbr_of_philos % 2)
			usleep(2000);
	}
	return (NULL);
}
