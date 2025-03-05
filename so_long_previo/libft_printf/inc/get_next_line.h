/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:37:04 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/24 12:03:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct lk_lst
{
	char			*string_content;
	struct lk_lst		*next;
}	t_lk_lst;

char	*get_next_line(int fd);
void	f_clean_memory(t_lk_lst **lk_lst, t_lk_lst *remanent_char, char *buffer);
void	f_copy_str(t_lk_lst *lk_lst, char *str);
int		f_find_newline(t_lk_lst *lk_lst);
int		f_length_to_nl(t_lk_lst *lk_lst);
t_lk_lst	*f_find_last_node(t_lk_lst *lk_lst);

#endif
