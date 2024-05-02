/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 00:06:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**create_args(char *str, ...)
{
	va_list	ap;
	char	*value;
	int		size;
	int		i;
	char	**args;

	size = ft_atoi(str);
	va_start(ap, str);
	i = 0;
	args = (char **)ft_calloc(size + 1, sizeof(char *));
	while (i < size)
	{
		value = va_arg(ap, char *);
		args[i++] = value;
	}
	args[i] = NULL;
	va_end(ap);
	return (args);
}

void	ft_exe_command(t_data *data)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	data->path = ft_strjoin("/bin/", data->args[0]);
	if (pid == 0)
		execve(data->path, data->args, NULL);
	else
		wait(NULL);
}

void	free_data(t_data *data)
{
	free(data->args);
	free(data->path);
}
