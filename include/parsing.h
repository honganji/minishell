/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:31 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:26 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;

void					parse_commands(t_token *tokens, t_data *data);
void					add_token_to_command(t_cmd *command, t_token *token);
void					add_command_to_list(t_list **lst, t_cmd *command);
void					process_commands(char *input);
void					print_commands(t_list *lst);
t_token					*tokenization(char **tokens);
int						what_token(char *str);
int						what_redir(char *str, int i);

#endif