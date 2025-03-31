/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:55:16 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/31 14:48:14 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../libft/libft.h"

/* linked list where each node holds a key=value pair from envp. */
typedef struct s_env
{
	char			*key;	//The name of the variable (e.g., "PATH")
	char			*value;	//The value of the variable (e.g., "/bin:/usr/bin")
	struct s_env	*next;	//Pointer to the next node in the list
}	t_env;

/* ----------------- FREE_ENV_LIST ------------------*/
void	free_env_list(t_env *env);
void	free_env_node(t_env *node);

/* ----------------- ENV_UTILS1 --------------------*/
int		ft_strcmp(const char *s1, const char *s2);	//compares 2 str charxchar
char	*get_env_value(t_env *env, const char *key);//retrieves Env Var value
void	set_env_value(t_env *env, const char *key, const char *value);
//Sets or updates the value of an existing env variable.
t_env	*init_env(char **envp);//Initializes list of env variables from envp.
t_env	*create_env_node(char *env_entry);//Creates a new t_env node

/* ----------------- ENV_UTILS2 --------------------*/
void	update_env_var(t_env *env, const char *key, const char *value);

#endif