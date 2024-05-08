/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:15:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "struct.h"
# include "utils.h"

void	ft_execve(char *str);
void	ft_chdir(char *path);
void	ft_echo(t_data *data, char *str, char *flag);
void	ft_pwd(void);
void	ft_env(t_data *data);
void	ft_export(t_data *data, char *str);
void	ft_exe_command(t_data *data, char *str, t_com com);
void	ft_unset(t_data *data, char *str);

#endif
