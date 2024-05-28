/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 18:47:30 by ytoshihi         ###   ########.fr       */
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
	if (content.com == ECH)
		ft_echo(content.args, data);
	else if (content.com == CD)
		ft_chdir(content.args, data);
	else if (content.com == PWD)
		ft_pwd(data);
	else if (content.com == EXPORT)
		ft_export(data);
	else if (content.com == UNSET)
		ft_unset(data);
	else if (content.com == ENV)
		ft_env(data->env_lst, data, content.args[1]);
	else if (content.com == EXIT)
		ft_exit(data, 1, content.args[1], content.args);
	else if (content.com == ETC)
		ft_execve(content.args, data);
}
