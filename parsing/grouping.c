/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/05 18:01:53 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_commands(t_token *tokens, t_data *data)
{
	t_cmd	*curr_command;
	t_token	*curr_token;
	int		is_first;

	curr_command = cmd_init();
	curr_token = tokens;
	data->cmd_lst = NULL;
	is_first = 1;
	while (curr_token != NULL)
	{
		if (store_command(data, &curr_command, &curr_token, &is_first) == 1)
			return ;
	}
	add_command_to_list(&(data->cmd_lst), curr_command);
}

t_com	detect_cmd_type(t_token *token)
{
	if (!token || !token->data)
		return (ETC);
	if (ft_strncmp(token->data, "echo", 5) == 0)
		return (ECH);
	else if (ft_strncmp(token->data, "cd", 3) == 0)
		return (CD);
	else if (ft_strncmp(token->data, "pwd", 4) == 0)
		return (PWD);
	else if (ft_strncmp(token->data, "export", 7) == 0)
		return (EXPORT);
	else if (ft_strncmp(token->data, "unset", 6) == 0)
		return (UNSET);
	else if (ft_strncmp(token->data, "env", 4) == 0)
		return (ENV);
	else if (ft_strncmp(token->data, "exit", 5) == 0)
		return (EXIT);
	else
		return (ETC);
}

void	add_token_to_command(t_data *data, t_cmd *command, t_token *token)
{
	int		is_skip;

	is_skip = 0;
	remove_quote(&token->data, &is_skip);
	if (token->data && !is_skip)
	{
		token->data = replace_env(data, token->data);
		if (!token->data)
			return ;
	}
	if (command->args == NULL)
	{
		command->args = malloc(sizeof(char *) * 2);
		if (command->args == NULL)
			return ;
		command->args[0] = token->data;
		command->args[1] = NULL;
	}
	else
		store_token(command, token);
}

void	add_command_to_list(t_list **head, t_cmd *new_command)
{
	ft_lstadd_back(head, ft_lstnew(new_command));
}
