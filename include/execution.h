/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/18 16:33:12 by adprzyby         ###   ########.fr       */
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

typedef struct s_data t_data;
typedef enum e_com t_com;
typedef struct s_cmd t_cmd;

void	ft_execve(char **args, t_data *data);
void	ft_chdir(char *path, t_data *data);
void	ft_echo(char **args);
void	ft_pwd(t_data *data);
void	ft_env(t_list *env_lst);
void	ft_export(t_data *data);
void	ft_unset(t_data *data);
void	ft_exe_command(t_data *data, t_cmd content);


#endif
