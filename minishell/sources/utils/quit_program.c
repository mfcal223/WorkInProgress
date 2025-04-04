/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:52 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/04 09:29:10 by mcalciat         ###   ########.fr       */
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
	rl_clear_history(); // Frees command history
	//printf("exit\n");// comentado para ver si es el culpable del doble mensaje de exit
	exit(status);
}

/**
 * TERMINAL OUTPUT
 * 
 * ==404083== LEAK SUMMARY:
==404083==    definitely lost: 0 bytes in 0 blocks
==404083==    indirectly lost: 0 bytes in 0 blocks
==404083==      possibly lost: 0 bytes in 0 blocks
==404083==    still reachable: 208,237 bytes in 225 blocks
==404083==         suppressed: 0 bytes in 0 blocks
==404083== 
==404083== For lists of detected and suppressed errors, rerun with: -s
==404083== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*
*
** 🔍 Why is this memory still reachable?
Valgrind is telling you that some memory was not freed at exit, but it was not leaked — meaning it’s still referenced and could theoretically be freed, 
but wasn't. This is by design in some libraries like readline.

GNU Readline internally allocates memory for command history, terminal handling, keymaps, and prompt management.

These allocations are never freed explicitly unless you call certain teardown functions (which aren't required for most shell usage).

✅ Is this a real problem?
No. Here’s why:
- These are not leaks. Valgrind even says:
			definitely lost: 0 bytes in 0 blocks
			indirectly lost: 0 bytes in 0 blocks
- It is just memory that wasn't freed on exit, but it's still accessible and accounted for. So technically: "still reachable."

🧼 Want to clean it up?
If you're being extra strict (e.g., for school or bonus points), you can explicitly clean up Readline:
			rl_clear_history(); // Frees command history
But you’ll still see some “reachable” memory due to deeper Readline internals unless you patch or recompile Readline itself — 
which is overkill and not required by the subject.
 */