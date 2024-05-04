/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 13:39:30 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// TODO enable to use env variable
void	ft_exe_command(t_data *data, char *str, t_com com)
{
	if (com == ECHO)
		ft_echo(str, "-n");
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
		ft_execve(data, str);
}
