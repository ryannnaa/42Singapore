/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:50:53 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/14 15:19:19 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct p_philo
{
	int				id;
	int				e_count;
	int64_t			eat;
	pthread_t		thread;
	struct p_data	*data;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

typedef struct p_data
{
	int				p_count;
	int				d_time;
	int				e_time;
	int				s_time;
	int				times_to_eat;
	int				s_flag;
	int				d_flag;
	int				count;
	int64_t			start;
	pthread_t		monitoring;
	pthread_mutex_t	print;
	pthread_mutex_t	flexi;
	pthread_mutex_t	death;
	pthread_mutex_t	counter;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

int					main(int argc, char **argv);
int					ft_error(char *msg);
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
int					create_mutex(t_data *p_data);
int					destroy_mutex(t_data *p_data);
int					start_loop(t_data *p_data);
int					create_thread(t_philo *p_data);
int64_t				get_time(void);
void				*daily_life(void *arg);
void				snooze(int ms, int64_t start);
void				*monitor(void *arg);
void				talk(char *s, t_philo *p);
void				nap(t_philo *p);
void				eat(t_philo *p);
void				ft_putstr_fd(char *s, int fd);
void				clean_struct(t_data *data);

#endif