/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:13:55 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/14 13:38:49 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_data *p_data)
{
	int	i;

	i = 0;
	p_data->forks = malloc(sizeof(pthread_mutex_t) * p_data->p_count);
	if (!p_data->forks)
	{
		ft_putstr_fd("Error: Failed to malloc for forks\n", 2);
		return (1);
	}
	while (i < p_data->p_count)
	{
		if (pthread_mutex_init(&p_data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&p_data->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&p_data->flexi, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&p_data->death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&p_data->counter, NULL) != 0)
		return (1);
	return (0);
}

int	destroy_mutex(t_data *p_data)
{
	int	i;

	i = 0;
	while (i < p_data->p_count)
	{
		if (pthread_mutex_destroy(&p_data->forks[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&p_data->print) != 0)
		return (1);
	if (pthread_mutex_destroy(&p_data->flexi) != 0)
		return (1);
	return (0);
}
