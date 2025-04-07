/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:53 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 16:15:32 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * bi_env - prints out the environment variables
 * @env_ll: linked list that contains key-value pairs of env variables
 *
 * Return: void
 */
int	bi_env(t_list **env_ll)
{
	print_env(env_ll);
	return (EXIT_SUCCESS);
}
