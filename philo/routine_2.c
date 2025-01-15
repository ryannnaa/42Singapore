/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:07:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/15 18:49:14 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	talk(char *s, t_philo *p)
{
	int64_t	timestamp;

	pthread_mutex_lock(&p->data->death);
	if (p->data->d_flag != 0)
	{
		pthread_mutex_unlock(&p->data->death);
		return ;
	}
	pthread_mutex_unlock(&p->data->death);
	timestamp = get_time();
	pthread_mutex_lock(&p->data->print);
	printf("%ld %d %s", timestamp - p->data->start, p->id, s);
	pthread_mutex_unlock(&p->data->print);
}

void	nap(t_philo *p)
{
	pthread_mutex_lock(&p->data->death);
	if (p->data->d_flag != 0)
	{
		pthread_mutex_unlock(&p->data->death);
		return ;
	}
	pthread_mutex_unlock(&p->data->death);
	talk("is sleeping\n", p);
	usleep(p->data->s_time * 1000);
}

void	sort_philo(t_philo *p)
{
	if (p->id % 2 != 0)
	{
		usleep(1000);
	}
	if (p->id % 2 != 0)
	{
		pthread_mutex_lock(p->left);
		talk("has taken a fork\n", p);
		pthread_mutex_lock(p->right);
		talk("has taken a fork\n", p);
	}
	else
	{
		pthread_mutex_lock(p->right);
		talk("has taken a fork\n", p);
		pthread_mutex_lock(p->left);
		talk("has taken a fork\n", p);
	}
}

void	eat(t_philo *p)
{
	if (p->data->p_count == 1)
	{
		talk("has taken a fork\n", p);
		usleep((p->data->d_time + 1) * 1000);
		return ;
	}
	sort_philo(p);
	pthread_mutex_lock(&p->data->flexi);
	p->eat = get_time();
	talk("is eating\n", p);
	pthread_mutex_unlock(&p->data->flexi);
	snooze(p->data->e_time, p->eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}
