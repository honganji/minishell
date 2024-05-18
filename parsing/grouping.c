/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/16 18:24:43 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_commands(t_token *tokens, t_data *data)
{
	t_cmd	*current_command;
	t_token	*current_token;

	current_command = cmd_init();
	current_token = tokens;
	data->cmd_lst = NULL;
	while (current_token != NULL)
	{
		if (current_token->type != PIPE)
		{
			if (current_token->type == REDIR)								//TODO handle escaped chars
				handle_redirections(current_token, data);
			else
				add_token_to_command(current_command, current_token);
		}
		else
		{
			add_command_to_list(&(data->cmd_lst), current_command);
			current_command = cmd_init();
		}
		current_token = current_token->next;
	}
	add_command_to_list(&(data->cmd_lst), current_command);
	print_commands(data->cmd_lst);
}

// The parse_commands function takes a linked list of tokens as input and groups them into commands based on the presence of pipe tokens
// It creates a new command whenever it encounters a pipe token,
// and adds the current token to the current command otherwise.

void	add_token_to_command(t_cmd *command, t_token *token)
{
	int		i;
	int		j;
	char	**new_args;

	i = 0;
	j = 0;
	if (command->args == NULL)
	{
		command->args = malloc(sizeof(char *) * 2);
		if (command->args == NULL)
			return ;
		command->args[0] = token->data;
		command->args[1] = NULL;
	}
	else
	{
		while (command->args[i] != NULL)
			i++;
		new_args = malloc(sizeof(char *) * (i + 2));
		if (new_args == NULL)
			return ;
		while (j < i)
		{
			new_args[j] = command->args[j];
			j++;
		}
		new_args[i] = token->data;
		new_args[i + 1] = NULL;
		free(command->args);
		command->args = new_args;
	}
}

// The add_token_to_command function takes a command and a token as input and adds the token to the command's arguments list.

void	add_command_to_list(t_list **head, t_cmd *new_command)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = new_command;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

// The add_command_to_list function takes a list of commands and a command as input and adds the command to the list.

void	print_commands(t_list *command_list)
{
	t_list	*current_node;
	int		i;
	t_cmd	*current_command;

	current_node = command_list;
	while (current_node != NULL)
	{
		current_command = (t_cmd *)current_node->content;
		printf("Command:\n");
		if (current_command->args != NULL)
		{
			i = 0;
			while (current_command->args[i] != NULL)
			{
				printf("Argument %d: %s\n", i, current_command->args[i]);
				i++;
			}
			printf("\n");
		}
		current_node = current_node->next;
	}
}
