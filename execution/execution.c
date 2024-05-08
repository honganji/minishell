/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:07:39 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_exe_command(t_data *data, char *str, t_com com)
{
	if (com == ECHO)
		ft_echo(data, str, "-n");
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
	else
		ft_execve(str);
}
