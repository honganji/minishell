/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:31 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/05 10:54:34 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;
typedef enum e_com		t_com;
typedef struct s_redir	t_redir;

void					parse_commands(t_token *tokens, t_data *data);
void					add_token_to_command(
							t_data *data, t_cmd *command, t_token *token);
void					add_command_to_list(t_list **lst, t_cmd *command);
void					process_commands(char *input, t_data *data);
t_com					detect_cmd_type(t_token *token);
t_token					*tokenization(char **tokens);
int						what_token(char *str);
int						is_redir(char *str, int i);
void					handle_redirections(t_token **tokens,
							t_data *data, t_cmd *current_command);
void					store_command(t_data *data, t_cmd **cmd,
							t_token **token, int *is_first);
void					store_token(t_cmd *command, t_token *token);
t_token					*split_combined_tokens(t_token *token);
t_token	*create_and_link_token(t_token *tmp, t_token **token,
		t_token **last_token, char *data);
		t_token	*create_new_token(t_token *token, int i);
		int	check_in_quotes(t_token *token, int i);
t_token	*check_redirections(t_token *token, int i);
#endif