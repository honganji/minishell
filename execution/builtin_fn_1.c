/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 17:21:53 by ytoshihi         ###   ########.fr       */
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
void	ft_execve(char **args, t_data *data)
{
	t_exe	params;

	params.status = 0;
	if (pipe(params.fds) == -1)
		critical_err(strerror(errno));
	params.tmp = args[0];
	args[0] = ft_strjoin("/", args[0]);
	args[0] = ft_check_exist(data, args[0]);
	if (!*(args[0]))
	{
		syntax_err(data, "command not found", params.tmp, 127);
		ft_input_data(data, "", 0);
		return ;
	}
	params.pid = fork();
	if (params.pid == 0)
		exe_builtin(params.fds, args);
	else
	{
		store_ec(data, params.status, params.fds, params.pid);
		args[0] = params.tmp;
		params.str = ft_read_file(params.fds[0]);
		close(params.fds[0]);
		ft_input_data(data, params.str, 0);
	}
}

/**
 * @brief change the current directory
 * After change the current directory, set empty string into STDIN
 * @param path path for the new path. It can be definite or relative path
 * @return void
 */
void	ft_chdir(char **args, t_data *data)
{
	char	buffer[256];
	char	*cur_dir;
	char	*path;

	if (!args[1])
		path = ((t_env *)ft_find_ele(data, "HOME")->content)->value;
	else
		path = args[1];
	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
	{
		data->exit_code = 1;
		syntax_err(NULL, "pwd: error retrieving current directory\n", NULL, 1);
	}
	register_env(data, "OLDPWD", cur_dir);
	if (chdir(path) == -1)
	{
		syntax_err(NULL, "cd: no such file or directory: ", path, 1);
		data->exit_code = 1;
		exit(EXIT_FAILURE);
	}
	ft_input_data(data, "", 0);
	data->exit_code = 0;
}

/**
 * @brief read the input and send it to STDIN
 * 
 * @param args arguments
 * @return void
 */
void	ft_echo(char **args, t_data *data)
{
	int		i;
	char	*str;

	i = 1;
	data->exit_code = 0;
	if (!args[1])
	{
		ft_input_data(data, "\n", 0);
		return ;
	}
	if (ft_strncmp(args[1], "-n", ft_strlen(args[1])))
	{
		str = ft_join_with_space(&args[i]);
		str = ft_free_strjoin(str, "\n");
	}
	else
		str = ft_join_with_space(&args[++i]);
	ft_input_data(data, str, 0);
}

/**
 * @brief get the current definite directory path
 * 
 * @return void
 */
void	ft_pwd(t_data *data)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
	{
		data->exit_code = 1;
		syntax_err(NULL, "pwd: error retrieving current directory\n", NULL, 1);
	}
	ft_input_data(data, ft_strjoin(cur_dir, "\n"), 0);
	data->exit_code = 0;
}

/**
 * @brief get all the env variable and send them to input parameter
 * 
 * Read all the node of a env variable list and combine using ft_free_strjoin
 * @param data data
 * @return void
 */
void	ft_env(t_list *env_lst, t_data *data)
{
	t_list	*tmp;
	char	*str;

	tmp = env_lst;
	str = ft_strdup("");
	if (!str)
		critical_err(strerror(errno));
	while (tmp)
	{
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).key);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "=");
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, (*(t_env *)(tmp->content)).value);
		if (!str)
			critical_err(strerror(errno));
		str = ft_free_strjoin(str, "\n");
		if (!str)
			critical_err(strerror(errno));
		tmp = tmp->next;
	}
	ft_input_data(data, str, 0);
	return (free(str), set_exit_code(data, 0));
}
