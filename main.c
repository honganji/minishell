/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 12:36:44 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// TODO For freeing
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

// // TODO delete
// // for displaying the input
// static void	check_input(t_data *data)
// {
//     t_list  *tmp;

// 	tmp = data->cmd_lst;
// 	while (tmp)
// 	{
// 		printf("command:\n");
// 		printf("cmd: %d\n", ((t_cmd *)tmp->content)->com);
// 		printf("args: %s\n", ((t_cmd *)tmp->content)->args[0]);
// 		printf("input: %s\n", ((t_cmd *)tmp->content)->input.file_name);
// 		printf("output: %s\n\n", ((t_cmd *)tmp->content)->output.file_name);
// 		tmp = tmp->next;
//     }
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
	initialize(data, env);
	while (1)
	{
		dup2(data->stdin_fd, STDIN_FILENO);
		input = readline("minishell: ");
		check_signal(data, input);
		// TODO delete
		printf("exit code: %d\n", data->exit_code);
		// exit when ctrl-d typed
		if (!input)
			exit(EXIT_SUCCESS);
		if (input)
		{
			// parsing
			process_commands(input, data);

			// // TODO delete
			// check_input(data);
			// execution
			ft_pipe(data);
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell");
	return (0);
}
