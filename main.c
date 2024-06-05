/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:42:02 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/05 11:14:17 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*input;

	(void)argc, (void)argv;
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
			ft_exit(data, 0, "0", NULL);
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
