/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/12 18:33:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"


t_cmd	**parse_commands(t_token *tokens)
{
	t_cmd_list **commands = cmd_list_init();
	t_cmd *current_command = cmd_init();
	t_token *current_token = tokens;

	while (current_token != NULL)
	{
		if (current_token->type != PIPE)
			add_token_to_command(current_command, current_token);
		else
		{
			add_command_to_list(commands, current_command);
			current_command = cmd_init();
		}
		current_token = current_token->next;
	}
	add_command_to_list(commands, current_command);
	printf("Commands parsed\n");
	return (commands);
}

// The parse_commands function takes a linked list of tokens as input and groups them into commands based on the presence of pipe tokens.
// It creates a new command whenever it encounters a pipe token, and adds the current token to the current command otherwise.

void	add_token_to_command(t_cmd *command, t_token *token)
{
	int i;

	i = 0;
	if (command->args == NULL)
	{
		command->args = malloc(sizeof(char *) * 2);
		command->args[0] = token->data;
		command->args[1] = NULL;
	}
	else
	{
		while (command->args[i] != NULL)
			i++;
		command->args = malloc(sizeof(char *) * (i + 2));
		command->args[i] = token->data;
		command->args[i + 1] = NULL;
	}
}

// The add_token_to_command function takes a command and a token as input and adds the token to the command's arguments list.

void add_command_to_list(t_cmd **commands, t_cmd *command)
{
	t_cmd *current;

	current = *commands;
	if (*commands == NULL)
		*commands = command;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = command;
		command->prev = current;
	}
}

// The add_command_to_list function takes a list of commands and a command as input and adds the command to the list.
