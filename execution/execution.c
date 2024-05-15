/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 15:32:29 by ytoshihi         ###   ########.fr       */
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
void	ft_exe_command(t_data *data, char *str, t_com com)
{
	if (com == ECHO)
		ft_echo(data, str, "-k");
	else if (com == CD)
		ft_chdir(str);
	else if (com == PWD)
		ft_pwd();
	else if (com == EXPORT)
		ft_export(data, str);
	else if (com == UNSET)
		ft_unset(data, str);
	else if (com == ENV)
		ft_env(data);
	else if (com == EXIT)
		exit(EXIT_SUCCESS);
	else if (com == ETC)
		ft_execve(str);
}
