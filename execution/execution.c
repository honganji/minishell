/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:11:47 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/02 19:27:58 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_exe_ls(void)
{
	char	*args[3];
	pid_t	pid;

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/ls", args, NULL);
	else
		wait(NULL);
}

void	ft_exe_echo(void)
{
	char	*args[4];
	pid_t	pid;

	args[0] = "echo";
	args[1] = "-n";
	args[2] = "Hello World!";
	args[3] = NULL;
	printf("size of args: %lu", sizeof(args)/sizeof(args[0]));
	pid = fork();
	if (pid == 0)
		execve("/bin/echo", args, NULL);
	else
		wait(NULL);
}

// void	ft_exe_pwd(void)
// {
// 	char	*args[4];
// 	pid_t	pid;

// 	args[0] = "echo";
// 	args[1] = "-n";
// 	args[2] = "Hello World!";
// 	args[3] = NULL;
// 	pid = fork();
// 	if (pid == 0)
// 		execve("/bin/echo", args, NULL);
// 	else
// 		wait(NULL);
// }
