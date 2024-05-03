/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 16:03:29 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// For other builtin functions
void	ft_execve(t_data *data, char *str)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid == 0)
	{
		data->args = ft_split(str, ' ');
		printf("%s part------------------\n", data->args[0]);
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
void	ft_echo(char *str)
{
	char	**arr;
	int		i;
	int		n_flag;

	arr = ft_split(str, ',');
	i = 0;
	n_flag = 0;
	// Check if there is -n flag
	if (!ft_strncmp(str, "-n", 2))
	{
		n_flag = 1;
		i = 1;
	}
	// print what you need to display
	printf("%s", arr[i]);
	if (n_flag)
		printf("\n");
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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
void	ft_env(void)
{
	extern char	**environ;

	while (*environ)
		printf("%s\n", *environ++);
}
