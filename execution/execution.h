/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/06 10:51:52 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../minishell.h"

typedef struct s_data	t_data;
typedef struct s_env	t_env;
typedef enum e_com	t_com;

void	ft_execve(char *str);
void	ft_chdir(char *path);
void	ft_echo(t_data *data, char *str, char *flag);
void	ft_pwd(void);
void	ft_env(t_data *data);
void	ft_export(t_data *data, char *str);
void	ft_exe_command(t_data *data, char *str, t_com com);
void	ft_unset(t_data *data, char *str);

#endif
