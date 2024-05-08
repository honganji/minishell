/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:30 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:08:08 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipe.h"

// // For pwd command
// static void	ft_pipe_pwd(int fd)
// {
// 	char	buffer[256];
// 	char	*cur_dir;

// 	cur_dir = getcwd(buffer, sizeof(buffer));
// 	if (!cur_dir)
// 		exit(EXIT_FAILURE);
// 	write(fd, cur_dir, ft_strlen(cur_dir) + 1);
// }

// For echo command
static void	ft_pipe_echo(char *str, char *flag)
{
	int		n_flag;

	n_flag = 0;
	// Check if there is -n flag
	if (!ft_strncmp(flag, "-n", 2))
		n_flag = 1;
	printf("%s", str);
	if (n_flag)
		printf("\n");
}

// static void	ft_create_pipe_v2(char *value)
// {
// 	int			fds[2];
// 	pid_t		pid;
// 	char		**argv;

// 	pipe(fds);
// 	pid = fork();
// 	argv = malloc(sizeof(char *));
// 	argv[0] = "sort";
// 	argv[1] = NULL;
// 	if (pid == 0)
// 	{
// 		close(fds[1]);
// 		printf("echo started\n");
// 		printf("input: %s", get_next_line(fds[0]));
// 		dup2(fds[0], STDIN_FILENO);
// 		close(fds[0]);
// 		ft_pipe_echo(value, "-n");
// 		printf("\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		printf("This is parent process\n");
// 		close(fds[0]);
// 		write(fds[1], "king\n", ft_strlen("king\n") + 1);
// 		close(fds[1]);
// 	}
// }

void	ft_create_pipe(void)
{
	int			fds[2];
	pid_t		pid;
	char		*value;

	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		close(fds[1]);
		value = get_next_line(fds[0]);
		// dup2(fds[0], STDIN_FILENO);
		printf("value: %s\n", value);
		close(fds[0]);
		// ft_create_pipe_v2(value);
		ft_pipe_echo("Yes I can!", "-n");
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	close(fds[0]);
	write(fds[1], "hello world", ft_strlen("hello world") + 1);
	close(fds[1]);
}
