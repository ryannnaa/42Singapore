/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:55:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/07 20:36:45 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *p_data)
{
	p_data->p_count = 0;
	p_data->d_time = 0;
	p_data->e_time = 0;
	p_data->s_time = 0;
	p_data->times_to_eat = -1;
	p_data->s_flag = 0;
	p_data->d_flag = 0;
	p_data->count = 0;
	p_data->start = 0;
	p_data->forks = NULL;
	p_data->philo = NULL;
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_arg(int argc, char **argv, t_data *p_data)
{
	p_data->p_count = ft_atoi(argv[1]);
	p_data->d_time = ft_atoi(argv[2]);
	p_data->e_time = ft_atoi(argv[3]);
	p_data->s_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		p_data->times_to_eat = ft_atoi(argv[5]);
		if (p_data->times_to_eat <= 0)
			return (1);
	}
	if (p_data->p_count <= 0 || p_data->d_time <= 0 || p_data->e_time <= 0
		|| p_data->s_time <= 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	p_data;

	if (argc < 5 || argc > 6)
	{
		return (ft_error("Error: Invalid number of arguments\n"));
	}
	else
	{
		init_struct(&p_data);
		if (check_arg(argc, argv) != 0)
			return (ft_error("Error: Input numbers only\n"));
		if (parse_arg(argc, argv, &p_data) != 0)
			return (ft_error("Error: Invalid argument value(s)\n"));
		if (create_mutex(&p_data) != 0)
			return (ft_error("Error: Failed to create mutex(es)\n"));
		p_data.philo = malloc(sizeof(t_philo) * p_data.p_count);
		if (!p_data.philo)
			return (ft_error("Error: Failed to malloc for Philo\n"));
		if (start_loop(&p_data) != 0)
			return (ft_error("Error: Failed to create thread(s)\n"));
		if (destroy_mutex(&p_data) != 0)
			return (ft_error("Error: Failed to destroy mutex(es)\n"));
		clean_struct(&p_data);
	}
	return (0);
}
