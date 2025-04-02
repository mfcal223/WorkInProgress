/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:52 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/02 16:38:46 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quit_program(t_env *env)
{
	rl_clear_history();
	free_env_list(env);
    exit(env->exit_status);
}
