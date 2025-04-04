/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:08:58 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/04 11:08:00 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../../includes/environment.h"

/**
 * @brief Prints all environment variables to stdout.
 *
 * @param env Linked list of environment variables.
 */
int	builtin_env(t_env *env)
{
	while (env)
	{
		if (env->value) // skip if variable is unset (like OLDPWD sometimes)
		{
			ft_putstr_fd(env->key, 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(env->value, 1);
		}
		env = env->next;
	}
	env->exit_status = 0;
	return (0);
}
