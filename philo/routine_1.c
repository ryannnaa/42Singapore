/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:33:56 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/15 18:46:41 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait(t_philo *p)
{
	pthread_mutex_lock(&p->data->flexi);
	p->eat = p->data->start;
	pthread_mutex_unlock(&p->data->flexi);
}

void	*daily_life(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	wait(p);
	while (p->e_count != p->data->times_to_eat)
	{
		pthread_mutex_lock(&p->data->death);
		if (p->data->d_flag != 0)
		{
			pthread_mutex_unlock(&p->data->death);
			return (NULL);
		}
		pthread_mutex_unlock(&p->data->death);
		talk("is thinking\n", p);
		if (p->id % 2 == 0)
			usleep(3000);
		eat(p);
		p->e_count++;
		nap(p);
	}
	pthread_mutex_lock(&p->data->counter);
	p->data->count++;
	pthread_mutex_unlock(&p->data->counter);
	return (NULL);
}

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_count)
	{
		pthread_mutex_lock(&data->flexi);
		if (get_time() - data->philo[i].eat > data->d_time
			&& data->philo[i].e_count != data->times_to_eat)
		{
			pthread_mutex_lock(&data->death);
			data->d_flag = 1;
			pthread_mutex_unlock(&data->death);
			printf("%ld %d died\n", get_time() - data->start, i + 1);
			pthread_mutex_unlock(&data->flexi);
			return (1);
		}
		pthread_mutex_unlock(&data->flexi);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->flexi);
	pthread_mutex_unlock(&data->flexi);
	usleep(10000);
	while (1)
	{
		if (check_death(data) != 0)
			return (NULL);
		pthread_mutex_lock(&data->counter);
		if (data->count == data->p_count)
		{
			pthread_mutex_unlock(&data->counter);
			return (NULL);
		}
		pthread_mutex_unlock(&data->counter);
	}
}
