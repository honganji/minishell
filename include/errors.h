/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:03:26 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/31 16:50:17 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "../42-c-library/library.h"
# include "minishell.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data	t_data;

void					critical_err(char *msg);
void					set_exit_code(t_data *data, int code);
void					syntax_err(t_data *data, char *str, char *cmd,
							int code);
int						check_syntax(t_data *data, t_token *tokens);
void					token_syntax_err(t_data *data, char *str, int code);
int						pipe_check(t_data *data, t_token *tmp, int first_in_lst,
							int first_in_cmd);
int						redir_check(t_data *data, t_token *tmp);

#endif