/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:37:51 by tiatan            #+#    #+#             */
/*   Updated: 2025/01/21 19:11:50 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    bi_echo(void *)
{
    //Echo with the option -n
}

void    bi_cd(void *)
{
    //cd with only a relative or absolute path
    //chdir
}

void    bi_pwd(void *)
{
    //pwd no options
    //getcwd
}

void    bi_export(void *)
{
    //export no options
}

void    bi_unset(void *)
{
    //unset no options
}

void    bi_env(void *)
{
    //env no options or arguments
}

void    bi_exit(void *)
{
    //exit no options
}
