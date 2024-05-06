/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/05 13:36:51 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	ft_create_pipe(void)
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
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fds[1]);
		if (execvp(argv[0], argv) < 0)
			exit(0);
	}
	close(fds[0]);
	dprintf(fds[1], "%s\n", "word");
	dprintf(fds[1], "%s\n", "king");
	dprintf(fds[1], "%s\n", "make");
	dprintf(fds[1], "%s\n", "apple");
	close(fds[1]);
}
