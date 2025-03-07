/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:29:56 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/24 12:03:17 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	f_length_to_nl(t_lk_lst *lk_lst)
{
	int	i;
	int	len;

	if (lk_lst == NULL)
		return (0);
	len = 0;
	while (lk_lst != NULL)
	{
		i = 0;
		while (lk_lst->string_content[i] != 0)
		{
			if (lk_lst->string_content[i] == '\n')
			{
				++len;
				return (len);
			}
			i++;
			len++;
		}
		lk_lst = lk_lst->next;
	}
	return (len);
}

void	f_copy_str(t_lk_lst *lk_lst, char *str)
{
	int	i;
	int	k;

	if (lk_lst == NULL)
		return ;
	k = 0;
	while (lk_lst != NULL)
	{
		i = 0;
		while (lk_lst->string_content[i] != 0)
		{
			if (lk_lst->string_content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = lk_lst->string_content[i++];
		}
		lk_lst = lk_lst->next;
	}
	str[k] = '\0';
}

int	f_find_newline(t_lk_lst *lk_lst)
{
	int	i;

	if (lk_lst == NULL)
		return (0);
	while (lk_lst)
	{
		i = 0;
		while (lk_lst->string_content[i] && i < BUFFER_SIZE)
		{
			if (lk_lst->string_content[i] == '\n')
				return (1);
			i++;
		}
		lk_lst = lk_lst->next;
	}
	return (0);
}

t_lk_lst	*f_find_last_node(t_lk_lst *lk_lst)
{
	if (lk_lst == NULL)
		return (NULL);
	while (lk_lst->next != NULL)
		lk_lst = lk_lst->next;
	return (lk_lst);
}

void	f_clean_memory(t_lk_lst **lk_lst, t_lk_lst *remanent_char, char *buffer)
{
	t_lk_lst	*temp;

	if (*lk_lst == NULL)
		return ;
	while (*lk_lst)
	{
		temp = (*lk_lst)->next;
		free((*lk_lst)->string_content);
		free(*lk_lst);
		*lk_lst = temp;
	}
	*lk_lst = NULL;
	if (remanent_char->string_content[0] != '\0')
		*lk_lst = remanent_char;
	else
	{
		free(buffer);
		free(remanent_char);
	}
}
