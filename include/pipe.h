/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:58 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 16:24:25 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"

typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;

int		ft_output_red(char *name, char *content, int is_ow);
void	ft_pipe(t_data *data);
void	handle_input_and_execute(t_data *data, t_cmd *cmd);
void	handle_output(t_data *data, t_cmd *cmd, t_list *lst);

#endif