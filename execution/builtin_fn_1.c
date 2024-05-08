/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:07:15 by ytoshihi         ###   ########.fr       */
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
	int		n_flag;
	char	*arg;

	n_flag = 0;
	arg = ft_rep_env(data, str);
	// Check if there is -n flag
	if (!ft_strncmp(flag, "-n", 2))
		n_flag = 1;
	printf("%s", arg);
	if (n_flag)
		printf("\n");
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
	printf("%s", cur_dir);
}

// For env command
void	ft_env(t_data *data)
{
	t_list	*tmp;

	tmp = data->env_lst;
	while (tmp)
	{
		printf("%s=%s\n", (*(t_env *)(tmp->content)).key,
			(*(t_env *)(tmp->content)).value);
		tmp = tmp->next;
	}
}
