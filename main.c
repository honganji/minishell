/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 21:57:52 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// static void	clear_lst(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (lst)
// 	{
// 		tmp = lst;
// 		free(((t_env *)tmp->content)->key);
// 		free(((t_env *)tmp->content)->value);
// 		free(tmp->content);
// 		lst = lst->next;
// 		free(tmp);
// 	}
// }

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char 	*input;

	(void)argc;
	(void)argv;
	data = (t_data *)ft_calloc(2, sizeof(t_data));
	if (!data)
		critical_err(strerror(errno));
	data->stdin_fd = dup(STDIN_FILENO);
	data->exit_code = 0;

	// Set the valuables
	set_val(data, env);

	// Set signal for ctrl-c and ctrl-backslash
	set_signal_fn();
	while (1)
	{
		dup2(data->stdin_fd, STDIN_FILENO);
		input = readline("minishell: ");
		// TODO delete
		// change exit code depending on the last exit code
		if (g_sig)
			data->exit_code = 1;
		printf("exit code: %d\n", data->exit_code);
		g_sig = 0;
		// exit when ctrl-d typed
		if (!input)
			exit(EXIT_SUCCESS);
		if (input)
		{
			// // parsing
			// process_commands(input, data);

			// // execution
			ft_pipe(data);
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell");
	return (0);
}
