/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:57:03 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/31 11:28:49 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO: test `getcwd()` failure case once this is built into full minishell.
/**
 * @brief Prints the current working directory.
 *
 * Uses getcwd() to retrieve the absolute path and writes it to stdout.
 * If getcwd() fails, prints an error message to stderr using perror().
 *
 * No arguments are supported. This mimics the behavior of the `pwd` shell builtin.
 */
int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
 