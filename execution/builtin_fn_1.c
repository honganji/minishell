/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/17 18:18:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief Executes a builtin function that is not made by us but installed in 
 * OS.
 *
 * This function forks a new process and executes the given command in it.
 * The output of the command is redirected to a temporary file.
 *
 * @param str The command to execute.
 * @return void
 * 
 */
void	ft_execve(char **args)
{
	pid_t	pid;
	int		fds[2];
	char	*tmp;
	char	*str;

	if (pipe(fds) == -1)
	{
		perror("Error pipe");
		return ;
	}
	tmp = args[0];
	args[0] = ft_strjoin("/", args[0]);
	args[0] = ft_check_exist(args[0]);
	if (!*args)
	{
		printf("minishell: command not found: %s\n", args[0]);
		ft_input_data("", 0);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		if (execve(args[0], args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		close(fds[1]);
		wait(NULL);
		args[0] = tmp;
		str = ft_read_file(fds[0]);
		close(fds[0]);
		ft_input_data(str, 0);
	}
}

/**
 * @brief change the current directory
 * After change the current directory, set empty string into STDIN
 * @param path path for the new path. It can be definite or relative path
 * @return void
 */
void	ft_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		perror("cd: no such file or directory: ");
		exit(EXIT_FAILURE);
	}
	ft_input_data("", 0);
}

/**
 * @brief read the input and send it to STDIN
 * 
 * @param args arguments
 * @return void
 */
void	ft_echo(char **args)
{
	int	i;

	i = 1;
	if (!ft_strncmp(args[i], "-n", 2))
	{
		i++;
		args[i] = ft_strjoin(args[i], "\n");
	}
	ft_input_data(args[i], 0);
}

/**
 * @brief get the current definite directory path
 * 
 * @return void
 */
void	ft_pwd(void)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
		exit(EXIT_FAILURE);
	ft_input_data(cur_dir, 0);
}

/**
 * @brief get all the env variable and send them to input parameter
 * 
 * Read all the node of a env variable list and combine using ft_free_strjoin
 * @param data data
 * @return void
 */
void	ft_env(t_list *env_lst)
{
	t_list	*tmp;
	char	*str;

	tmp = env_lst;
	str = ft_strdup("");
	while (tmp)
	{
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).key);
		str = ft_free_strjoin(str, "=");
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).value);
		str = ft_free_strjoin(str, "\n");
		tmp = tmp->next;
	}
	ft_input_data(str, 0);
	free(str);
}
