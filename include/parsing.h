/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:31 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 13:31:42 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;
typedef enum e_com		t_com;

void					parse_commands(t_token *tokens, t_data *data);
void					add_token_to_command(t_cmd *command, t_token *token);
void					add_command_to_list(t_list **lst, t_cmd *command);
void					process_commands(char *input, t_data *data);
t_com 					detect_cmd_type(t_token *token);
void					print_commands(t_list *lst);	//TODO remove
t_token					*tokenization(char **tokens);
void					rv_quotes(char *str);
int						what_token(char *str);
int						is_redir(char *str, int i);
void					handle_redirections(t_token *tokens, t_data *data);

#endif