/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:17 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/02 23:42:53 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdarg.h>
# include "../42-c-library/library.h"

typedef struct s_data
{
	char	**args;
	char	*path;
}t_data;

void	create_pipe(void);
void	ft_exe_ls(void);
void	ft_exe_echo(void);
char	**create_args(char *str, ...);
void	ft_exe_command(t_data *data);
void	free_data(t_data *data);

#endif
