/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:55:16 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 16:04:29 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../libft/libft.h"
# include <limits.h>

/* linked list where each node holds a key=value pair from envp. */
typedef struct s_env
{
	char			*key;	//The name of the variable (e.g., "PATH")
	char			*value;	//The value of the variable (e.g., "/bin:/usr/bin")
	struct s_env	*next;	//Pointer to the next node in the list
	int				exit_status;//tracks the exit status = shell's global $?.
}	t_env;

/* ----------------- FREE_ENV_LIST ------------------*/
void	free_env_list(t_env *env);
void	free_env_node(t_env *node);

/* ----------------- ENV_UTILS1 --------------------*/
int		ft_strcmp(const char *s1, const char *s2);
char	*get_env_value(t_env *env, const char *key);
t_env	*init_env(char **envp);
t_env	*create_env_node(char *env_entry);

/* ----------------- ENV_UTILS2 --------------------*/
void	add_env_variable(t_env *last, const char *key, const char *value);
void	set_env_value(t_env *env, const char *key, const char *value);
int		is_valid_identifier(char *str);
int		env_list_size(t_env *env);

#endif