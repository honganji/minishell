/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/11 13:24:15 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// For other builtin functions
void	ft_execve(char *str)
{
	pid_t	pid;
	char	**args;
	char	*path;

	args = ft_split(str, ' ');
	path = ft_check_exist(args[0]);
	if (!*path)
	{
		printf("minishell: command not found: %s", str);
		free(path);
		free_arr(args);
		return ;
	}
	free(args[0]);
	args[0] = path;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		free_arr(args);
		wait(NULL);
	}
}

// For cd command
void	ft_chdir(char *path)
{
	if (chdir(path) == -1)
		exit(EXIT_FAILURE);
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
	free(arg);
}

// For pwd command
void	ft_pwd(void)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
		exit(EXIT_FAILURE);
	ft_input_data(cur_dir, 0);
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
	free(str);
}
