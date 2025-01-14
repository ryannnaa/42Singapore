/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:56:36 by tiatan            #+#    #+#             */
/*   Updated: 2024/11/04 00:35:42 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_arg(t_stack *list, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && (argv[i][j] == '+' || argv[i][j] == '-'))
			j++;
		if (argv[i][j] == '\0')
			ft_error("Error: Input only numbers\n", list);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				free_2d(argv);
				ft_error("Error: Input only numbers\n", list);
			}
			j++;
		}
		i++;
	}
}

void	add_to_list(t_stack *list, char **temp)
{
	int		i;
	long	j;

	i = 0;
	while (temp[i])
	{
		j = ft_atol(temp[i]);
		if (j <= INT_MAX && j >= INT_MIN)
		{
			insert_node(list, (int)j);
			list->size++;
		}
		else
		{
			free_2d(temp);
			ft_error("Error: Number exceeds allowed limit of INT\n", list);
		}
		i++;
	}
}

void	create_list(t_stack *list, int argc, char **argv)
{
	int		i;
	char	**temp;

	i = 0;
	while (i < argc - 1)
	{
		temp = ft_split(argv[i + 1], ' ');
		if (!temp)
		{
			ft_putstr_fd("Error: Split failed\n", 2);
			exit(1);
		}
		check_arg(list, temp);
		add_to_list(list, temp);
		free_2d(temp);
		i++;
	}
}

int	check_dup(t_stack *list)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list->head;
	while (current_node->next != list->head)
	{
		next_node = current_node->next;
		while (next_node != current_node)
		{
			if (current_node->data == next_node->data)
				return (1);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	list_a;
	t_stack	list_b;

	if (argc < 2)
		return (1);
	else
	{
		init_list(&list_a);
		init_list(&list_b);
		create_list(&list_a, argc, argv);
		if (list_a.head == NULL)
			return (1);
		if (check_dup(&list_a))
			ft_error("Error: Duplicate found\n", &list_a);
		if (check_sorted(&list_a))
		{
			free_list(&list_a);
			return (0);
		}
		index_stack(&list_a);
		sort_list(&list_a, &list_b);
		free_list(&list_a);
		free_list(&list_b);
		return (0);
	}
}
