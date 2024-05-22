/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 16:27:49 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief Executes a builtin function that is not made by us but installed in 
 * OS.
 *
 * This function forks a new process and executes the given command in it.
 * The output of the command is redirected to a temporary file.
 *
 * @param str The command to execute.
 * @return void
 * 
 */
void	ft_execve(char **args, t_data *data)
{
	t_exe	params;

	params.status = 0;
	if (pipe(params.fds) == -1)
		critical_err(strerror(errno));
	params.tmp = args[0];
	args[0] = ft_strjoin("/", args[0]);
	args[0] = ft_check_exist(data, args[0]);
	if (!*(args[0]))
	{
		syntax_err(data, "command not found", params.tmp, 127);
		ft_input_data(data, "", 0);
		return ;
	}
	params.pid = fork();
	if (params.pid == 0)
		exe_builtin(params.fds, args);
	else
	{
		store_ec(data, params.status, params.fds, params.pid);
		args[0] = params.tmp;
		params.str = ft_read_file(params.fds[0]);
		close(params.fds[0]);
		ft_input_data(data, params.str, 0);
	}
}
