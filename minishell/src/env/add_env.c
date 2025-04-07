/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:10:48 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 16:17:11 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	add_env_direct(t_list **env_ll, char *k, char *v)
{
	t_env		*key_v;
	t_list		*node;

	key_v = malloc(sizeof(t_env));
	fill_key(key_v, ft_strlen(k), k);
	fill_value(key_v, ft_strlen(v), v);
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
	free(k);
	free(v);
	return (EXIT_SUCCESS);
}

int	find_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	return (i);
}

int	env_a(char *key, char*value, t_list **env_ll)
{
	if (find_node(env_ll, key) == NULL)
		return (add_env_direct(env_ll, key, value));
	else
	{
		update_value(env_ll, key, value);
		free(key);
		return (EXIT_SUCCESS);
	}
}

int	add_env(char **env, int i, t_list **env_ll, t_shell *shell)
{
	char	*key;
	char	*value;
	char	*eq;
	int		key_len;

	eq = ft_strchr(env[i], '=');
	key_len = find_eq(env[i]);
	if (key_len == 0 || check_key(key_len, env[i]))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(env[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		shell->exit = 1;
		return (1);
	}
	key = ft_substr(env[i], 0, key_len);
	value = ft_substr(env[i], key_len + 1, ft_strlen(env[i]) - key_len);
	if (eq == NULL)
	{
		free(value);
		return (add_empty_key(env_ll, env, key, i));
	}
	return (env_a(key, value, env_ll));
}
