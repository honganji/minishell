/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/25 10:11:44 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*input;

	(void)argc;
	(void)argv;
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		critical_err(strerror(errno));
	initialize(data, env);
	while (1)
	{
		dup2(data->stdin_fd, STDIN_FILENO);
		input = readline("minishell: ");
		check_signal(data);
		if (!input)
			ft_exit(0, data, 0);
		if (!*input)
			continue ;
		if (input)
		{
			process_commands(input, data);
			ft_pipe(data);
		}
		free_cmd_lst(data);
	}
	return (0);
}
