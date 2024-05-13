/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 11:51:51 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_exe_command(t_data *data, char *str, t_com com)
{
	if (com == ECHO)
		ft_echo(data, str, "-k");
	else if (com == CD)
		ft_chdir(data, str);
	else if (com == PWD)
		ft_pwd(data);
	else if (com == EXPORT)
		ft_export(data, str);
	else if (com == UNSET)
		ft_unset(data, str);
	else if (com == ENV)
		ft_env(data);
	else if (com == EXIT)
		exit(EXIT_SUCCESS);
	else if (com == ETC)
		ft_execve(data, str);
}
