/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 18:47:20 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"

typedef struct s_data	t_data;
typedef enum e_com		t_com;
typedef struct s_cmd	t_cmd;

typedef struct s_exe
{
	pid_t	pid;
	int		fds[2];
	char	*tmp;
	char	*str;
	int		status;
}			t_exe;

typedef struct s_ft_env
{
	t_list	*tmp;
	char	*str;
}t_ft_env;

void	ft_execve(char **args, t_data *data);
void	ft_chdir(char **args, t_data *data);
void	ft_echo(char **args, t_data *data);
void	ft_pwd(t_data *data);
void	ft_env(t_list *env_lst, t_data *data, char *arg);
void	ft_export(t_data *data);
void	ft_unset(t_data *data);
void	ft_exe_command(t_data *data, t_cmd content);
void	ft_exit(t_data *data, int is_cmd, char *arg, char **arr);

#endif
