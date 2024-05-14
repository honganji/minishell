/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:31 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/14 16:46:12 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef struct s_token t_token;
typedef struct s_cmd	t_cmd;

void				parse_commands(t_token *tokens);
void				add_token_to_command(t_cmd *command, t_token *token);
void				add_command_to_list(t_cmd **head, t_cmd *command);
void				process_commands(char *input);
void 				print_commands(t_cmd *command);
t_token				*tokenization(char **tokens);
int					what_token(char *str);
int					what_redir(char *str, int i);

#endif