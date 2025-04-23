/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:24:55 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/18 17:04:32 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/minishell.h"

/*
** Checks whether the character at position `i` in the input string is a 
tilde (`~`) that should be expanded to the user's home directory.
**
** A tilde is expanded if:
** - It's at the start of the input, or preceded by a space (i.e., at the 
start of a word)
** - It's followed by either a slash (`/`) or the end of the string (`\0`)
**
** Examples:
** - "~" → expands
** - "~/folder" → expands
** - "echo ~" → expands
** - "path~/folder" → ❌ does not expand
*/
int	is_tilde_start(char *input, int i)
{
	return (input[i] == '~'
		&& (i == 0 || input[i - 1] == ' ')
		&& (input[i + 1] == '/' || input[i + 1] == '\0'));
}

/*
** Appends the value of the HOME environment variable to the result string
** during expansion. This is used when expanding a tilde (`~`) into the full
** home directory path.
**
** - Retrieves HOME from the environment
** - Appends its value character by character into `exp->result`
** - Updates `exp->result_id` accordingly
**
** If HOME is not set, nothing is appended.
*/
void	append_home(t_expand *exp, t_env *env)
{
	char	*home;
	int		j;

	home = get_env_value(env, "HOME");
	if (!home)
		return ;
	j = 0;
	while (home[j])
		exp->result[(exp->result_id)++] = home[j++];
}
