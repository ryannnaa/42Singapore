/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:21:00 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/07 15:39:58 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

void	clean_struct(t_data *data)
{
	if (data->philo)
		free(data->philo);
	data->philo = NULL;
	if (data->forks)
		free(data->forks);
	data->forks = NULL;
}
