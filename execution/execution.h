/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 15:02:48 by ytoshihi         ###   ########.fr       */
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

typedef struct s_data
{
	char	**args;
	char	*path;
}t_data;

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

void	create_pipe(void);
void	ft_execve(t_data *data, char *str);
void	ft_chdir(char *path);
void	ft_echo(char *str);
void	ft_pwd(void);
void	ft_env(void);
void	ft_exe_command(t_data *data, char *str, t_com com);

#endif
