/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 17:11:44 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// For other builtin functions
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
void	ft_execve(char *str)
{
	char	**args;
	char	*path;
	pid_t	pid;
	int		fd;

	fd = open(TMP_FILE, O_RDWR | O_CREAT, 0644);
	str = ft_strdup(str);
	args = ft_split(str, ' ');
	path = ft_check_exist(args[0]);
	if (!*path)
	{
		// printf("minishell: command not found: %s\n", str);
		handle_err(NULL, args[0], 127);
		ft_input_data("", 0);
		free(str);
		free(path);
		free_arr(args);
		return ;
	}
	free(str);
	free(args[0]);
	args[0] = path;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		if (execve(path, args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	free_arr(args);
	wait(NULL);
	store_output();
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
		// perror("cd: no such file or directory: ");
		handle_err(NULL, path, 1);
		exit(EXIT_FAILURE);
	}
	ft_input_data("", 0);
}

/**
 * @brief read the input and send it to STDIN
 * 
 * @param data data
 * @param str string to read
 * @param flag flag string
 * @return void
 */
void	ft_echo(t_data *data, char *str, char *flag)
{
	char	*arg;

	arg = ft_rep_env(data, str);
	if (!ft_strncmp(flag, "-n", 2))
	{
		// perror("echo: illegal option -- n\n");
		handle_err(data, arg, 1);
		arg = ft_free_strjoin(arg, "\n");
	}
	ft_input_data(arg, 0);
	free(arg);
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
	{
		handle_err(NULL, "pwd: error retrieving current directory\n", 1);
		exit(EXIT_FAILURE);
	}
	ft_input_data(cur_dir, 0);
}

/**
 * @brief get all the env variable and send them to input parameter
 * 
 * Read all the node of a env variable list and combine using ft_free_strjoin
 * @param data data
 * @return void
 */
void	ft_env(t_data *data)
{
	t_list	*tmp;
	char	*str;

	tmp = data->env_lst;
	str = ft_strdup("");
	if (!str)
		handle_err(data, "env: error duplicating string\n");
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
