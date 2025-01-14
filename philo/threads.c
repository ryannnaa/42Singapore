/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:18:49 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/09 18:17:46 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_data *p_data, t_philo *p, int i)
{
	p->id = i + 1;
	p->e_count = 0;
	p->eat = 0;
	p->data = p_data;
	p->left = &p_data->forks[i];
	if (p->id == p_data->p_count)
		p->right = &p_data->forks[0];
	else
		p->right = &p_data->forks[i + 1];
	return (pthread_create(&p_data->philo[i].thread, NULL, &daily_life, p));
}

int	start_loop(t_data *p_data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&p_data->flexi);
	while (i < p_data->p_count)
	{
		if (create_philo(p_data, &p_data->philo[i], i) != 0)
			return (ft_error("Error: Failed to create thread(s)\n"));
		i++;
	}
	if (pthread_create(&p_data->monitoring, NULL, &monitor, p_data) != 0)
		return (ft_error("Error: Failed to create monitoring thread\n"));
	p_data->s_flag = 1;
	p_data->start = get_time();
	pthread_mutex_unlock(&p_data->flexi);
	i = 0;
	while (i < p_data->p_count)
	{
		if (pthread_join(p_data->philo[i].thread, NULL) != 0)
			return (ft_error("Error: Failed to join thread(s)\n"));
		i++;
	}
	if (pthread_join(p_data->monitoring, NULL) != 0)
		return (ft_error("Error: Failed to join Monitoring thread\n"));
	return (0);
}
