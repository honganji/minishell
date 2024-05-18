/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/18 15:52:40 by adprzyby         ###   ########.fr       */
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
	while (1)
	{
		// TODO reset STDIN
		dup2(data->stdin_fd, STDIN_FILENO);
		input = readline("minishell: ");
		if (input)
		{
			// process_commands(input, data);
			// // command test

			// pipe
			ft_pipe(data);
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	// system("leaks minishell");
	return (0);
}
