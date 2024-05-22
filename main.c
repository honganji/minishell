/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 17:03:53 by ytoshihi         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*input;

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
		check_signal(data);
		if (!input)
			exit(EXIT_SUCCESS);
		if (input)
		{
			process_commands(input, data);
			ft_pipe(data);
		}
	}
	// clear_lst(data->env_lst);
	// free(data);
	return (0);
}
