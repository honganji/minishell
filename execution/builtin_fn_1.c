/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 11:02:49 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// For other builtin functions
// TODO deal with the command doesn't exist in the OS
void	ft_execve(t_data *data, char *str)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid == 0)
	{
		data->args = ft_split(str, ' ');
		data->path = ft_strjoin("/bin/", data->args[0]);
		if (execve(data->path, data->args, NULL) == -1)
		{
			printf("Error in execve...");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

// For cd command
void	ft_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		printf("Error in chdir...");
		exit(EXIT_FAILURE);
	}
}

// For echo command
void	ft_echo(char *str, char *flag)
{
	int	i;
	int	n_flag;

	i = 0;
	n_flag = 0;
	// Check if there is -n flag
	if (!ft_strncmp(flag, "-n", 2))
	{
		n_flag = 1;
		i = 1;
	}
	// print what you need to display
	printf("%s", str);
	if (n_flag)
		printf("\n");
}

// For pwd command
void	ft_pwd(void)
{
	char	buffer[256];
	char	*cur_dir;

	cur_dir = getcwd(buffer, sizeof(buffer));
	if (!cur_dir)
	{
		printf("Error in pwd...");
		exit(EXIT_FAILURE);
	}
	printf("%s", cur_dir);
}

// For env command
// TODO the order is different from the original env function so you should fix
void	ft_env(t_data *data)
{
	t_list	*tmp;

	tmp = data->env_lst;
	while (data->env_lst)
	{
		printf("%s=%s\n", (*(t_env *)((data->env_lst)->content)).key,
			(*(t_env *)((data->env_lst)->content)).value);
		data->env_lst = (data->env_lst)->next;
	}
	data->env_lst = tmp;
}
