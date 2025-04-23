/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:58:19 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/18 17:22:03 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STATUS_H
# define EXIT_STATUS_H

# define EXIT_SUCCESS        0
# define EXIT_FAILURE  1
# define EXIT_INVALID_USAGE  2
# define EXIT_COMMAND_NOT_FOUND 127
# define EXIT_NOT_EXECUTABLE 126
# define EXIT_NON_NUMERIC    255

# include <errno.h>
# include <stdlib.h>
# include "../libft/libft.h"

#endif