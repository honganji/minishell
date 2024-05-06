/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/06 18:03:11 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

// For pwd command
static void	ft_pipe_pwd(int fd)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
		exit(EXIT_FAILURE);
	write(fd, cur_dir, ft_strlen(cur_dir) + 1);
}

void	ft_create_pipe(int i)
{
	int			fds[2];
	pid_t		pid;
	char		**argv;

	pipe(fds);
	pid = fork();
	argv = malloc(sizeof(char *));
	argv[0] = "sort";
	argv[1] = NULL;
	if (pid == 0)
	{
		printf("index: %d\n", i);
		if (i < 1)
		{
			ft_create_pipe(1);
			i++;
		}
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fds[1]);
		ft_pipe_pwd(STDOUT_FILENO);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("This is parent process\n");
	}
	close(fds[0]);
	write(fds[1], "word\n", ft_strlen("word") + 1);
	write(fds[1], "king\n", ft_strlen("king") + 1);
	write(fds[1], "make\n", ft_strlen("make") + 1);
	write(fds[1], "apple\n", ft_strlen("apple") + 1);
	close(fds[1]);
}
