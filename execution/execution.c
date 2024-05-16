/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/16 21:10:42 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief Depends on the command, run a function for each one.
 * 
 * If there is no
 * function that I made, it runs builtin function
 * 
 * @param data data
 * @param str args including command
 * @param com enum that expresses which command they use
 * @return void
 */
void	ft_exe_command(t_data *data, t_cmd content)
{
	// TODO delete
	// printf("arg: %s\n", content.args[0]);
	if (content.com == ECHO)
		ft_echo(content.args);
	else if (content.com == CD)
		ft_chdir(content.args[1]);
	else if (content.com == PWD)
		ft_pwd();
	else if (content.com == EXPORT)
		ft_export(data);
	else if (content.com == UNSET)
		ft_unset(data);
	else if (content.com == ENV)
		ft_env(data->env_lst);
	else if (content.com == EXIT)
		exit(EXIT_SUCCESS);
	else if (content.com == ETC)
		ft_execve(content.args);
}
