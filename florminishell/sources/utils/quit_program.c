/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:52 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/23 09:07:16 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * Handles freeing and final exit.
 * The last exit status is save in a temp variable "status"
 *     to be able to free the structure and avoid leaks
 */
void	quit_program(t_env *env)
{
	int	status;

	status = env->exit_status;
	free_env_list(env);
	rl_clear_history();
	exit(status);
}
