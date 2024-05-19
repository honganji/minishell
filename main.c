/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/19 21:21:27 by ytoshihi         ###   ########.fr       */
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

	// Set the valuables
	set_val(data, env);

	// Set signal for ctrl-c, ctrl-d, and ctrl-backslash
	rl_catch_signals = 0;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_bs);
	while (1)
	{
		// TODO delete
		printf("global sig: %d", g_sig);
		dup2(data->stdin_fd, STDIN_FILENO);
		input = readline("minishell: ");
		// FOR ctrl-d
		if (!input)
			exit(EXIT_SUCCESS);
		if (input)
		{
			// // parsing
			// process_commands(input, data);

			// execution
			ft_pipe(data);
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell");
	return (0);
}
