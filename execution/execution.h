/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 20:58:48 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include "../42-c-library/library.h"

typedef enum e_com
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}t_com;

typedef struct s_env
{
	char	*key;
	char	*value;
}t_env;

typedef struct s_data
{
	char	**args;
	char	*path;
	t_env	*arr;
	t_list	*env_lst;
}t_data;

void	create_pipe(void);
void	ft_execve(t_data *data, char *str);
void	ft_chdir(char *path);
void	ft_echo(char *str);
void	ft_pwd(void);
void	ft_env(t_data *data);
void	ft_exe_command(t_data *data, char *str, t_com com);
void	store_env(t_data **data);

#endif
