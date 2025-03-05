/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:29:48 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/24 12:03:27 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	f_remanent_lk_lst(t_lk_lst **lk_lst)
{
	t_lk_lst	*last_element;
	t_lk_lst	*remanent_char;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	remanent_char = malloc(sizeof(t_lk_lst));
	if (buffer == NULL || remanent_char == NULL)
		return ;
	last_element = f_find_last_node(*lk_lst);
	i = 0;
	k = 0;
	while (last_element->string_content[i] != '\0'
		&& last_element->string_content[i] != '\n')
		i++;
	while (last_element->string_content[i] != '\0'
		&& last_element->string_content[i++])
		buffer[k++] = last_element->string_content[i];
	buffer[k] = '\0';
	remanent_char->string_content = buffer;
	remanent_char->next = NULL;
	f_clean_memory(lk_lst, remanent_char, buffer);
}

char	*f_extract_line(t_lk_lst *lk_lst)
{
	int		str_len;
	char	*str_display;

	if (lk_lst == NULL)
		return (NULL);
	str_len = f_length_to_nl(lk_lst);
	str_display = malloc(str_len + 1);
	if (str_display == NULL)
		return (NULL);
	f_copy_str(lk_lst, str_display);
	return (str_display);
}

void	f_append_in_lk_lst(t_lk_lst **lk_lst, char *buffer)
{
	t_lk_lst	*new_element;
	t_lk_lst	*last_element;

	last_element = f_find_last_node(*lk_lst);
	new_element = malloc(sizeof(t_lk_lst));
	if (new_element == NULL)
		return ;
	if (last_element == NULL)
		*lk_lst = new_element;
	else
	{
		last_element->next = new_element;
	}
	new_element->string_content = buffer;
	new_element->next = NULL;
}

void	f_create_lk_lst(t_lk_lst **lk_lst, int fd)
{
	int		ch_read;
	char	*buffer;

	while (!f_find_newline(*lk_lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		ch_read = read (fd, buffer, BUFFER_SIZE);
		if (ch_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[ch_read] = '\0';
		f_append_in_lk_lst(lk_lst, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_lk_lst	*lk_lst = NULL;
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	f_create_lk_lst(&lk_lst, fd);
	if (lk_lst == NULL)
		return (NULL);
	next_line = f_extract_line(lk_lst);
	f_remanent_lk_lst(&lk_lst);
	return (next_line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	int	num_lines;

	num_lines = 1;
	fd = open("text1.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", num_lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}*/
