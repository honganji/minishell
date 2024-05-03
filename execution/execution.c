/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 13:43:23 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_execve(t_data *data, char *str)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid == 0)
	{
		data->args = ft_split(str, ' ');
		printf("%s part------------------\n", data->args[0]);
		data->path = ft_strjoin("/bin/", data->args[0]);
		execve(data->path, data->args, NULL);
	}
	else
		wait(NULL);
}

// TODO enable to use env variable
void	ft_exe_command(t_data *data, char *str, t_com com)
{
	if (com == ECHO || com == PWD)
		ft_execve(data, str);
}
