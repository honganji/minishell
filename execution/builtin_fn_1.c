/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:09 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// For other builtin functions
void	ft_execve(t_data *data, char *str)
{
	char	**args;
	char	*path;
	pid_t	pid;
	int 	fd;

	fd = open(TMP_FILE, O_RDWR | O_CREAT, 0644);
	str = ft_strjoin(str, " ");
	str = ft_free_strjoin(str, data->output);
	args = ft_split(str, ' ');
	path = ft_check_exist(args[0]);
	if (!*path)
	{
		printf("minishell: command not found: %s\n", str);
		free(data->output);
		data->output = ft_strdup("");
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
	store_output(data);
}

// For cd command
void	ft_chdir(t_data *data, char *path)
{
	if (chdir(path) == -1)
	{
		perror("cd: no such file or directory: ");
		exit(EXIT_FAILURE);
	}
	free(data->output);
	data->output = ft_strdup("");
	ft_input_data("", 0);
}

// For echo command
void	ft_echo(t_data *data, char *str, char *flag)
{
	char	*arg;

	arg = ft_rep_env(data, str);
	// Check if there is -n flag
	if (!ft_strncmp(flag, "-n", 2))
		arg = ft_free_strjoin(arg, "\n");
	ft_input_data(arg, 0);
	free(data->output);
	data->output = ft_strdup(arg);
	free(arg);
}

// For pwd command
void	ft_pwd(t_data *data)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
		exit(EXIT_FAILURE);
	ft_input_data(cur_dir, 0);
	free(data->output);
	data->output = ft_strdup(cur_dir);
}

// For env command
void	ft_env(t_data *data)
{
	t_list	*tmp;
	char	*str;

	tmp = data->env_lst;
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
	free(data->output);
	data->output = ft_strdup(str);
	free(str);
}
