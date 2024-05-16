/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/16 21:21:09 by ytoshihi         ###   ########.fr       */
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
	// TODO modify
	int		saved_fd = dup(STDIN_FILENO);

	(void)argc;
	(void)argv;
	data = (t_data *)ft_calloc(2, sizeof(t_data));

	// Set the valuables
	set_val(data, env);
	while (1)
	{
		// TODO reset STDIN
		dup2(saved_fd, STDIN_FILENO);
		input = readline("Enter command: ");
		if (input)
		{
			// process_commands(input);
			// // command test
			// command_test(data);

			// pipe test
			pipe_test(data);

			// // redirection test
			// red_test(data);               
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell");
	return (0);
}
