/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/15 16:39:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

void	parse_commands(t_token *tokens)
{
	t_exe *current_command = cmd_init();
	t_exe *head = NULL;
	t_token *current_token = tokens;

	while (current_token != NULL)
	{
		if (current_token->type != PIPE)
			add_token_to_command(current_command, current_token);
		else
		{
			add_command_to_list(&head, current_command);
			current_command = cmd_init();
		}
		current_token = current_token->next;
	}
	add_command_to_list(&head, current_command);
	print_commands(head);
}

// The parse_commands function takes a linked list of tokens as input and groups them into commands based on the presence of pipe tokens.
// It creates a new command whenever it encounters a pipe token, and adds the current token to the current command otherwise.

void add_token_to_command(t_exe *command, t_token *token) {
    int i = 0;
	int j = 0;
    if (command->args == NULL)
	{
        command->args = malloc(sizeof(char *) * 2);
        if (command->args == NULL)
            return;
        command->args[0] = token->data;
        command->args[1] = NULL;
    }
	else
	{
        while (command->args[i] != NULL)
            i++;
        char **new_args = malloc(sizeof(char *) * (i + 2));
        if (new_args == NULL)
            return;
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

void add_command_to_list(t_exe **head, t_exe *new_command)
{
	t_exe *current;

	if (*head == NULL)
		(*head) = new_command;
	else
	{
		current = (*head);
		while (current->next != NULL)
			current = current->next;
		current->next = new_command;
		new_command->prev = current;
	}
}

// The add_command_to_list function takes a list of commands and a command as input and adds the command to the list.

void print_commands(t_exe *command)
{
	t_exe *current_command = command;
	int i;

	while (current_command != NULL) {
		printf("Command: ");
		if (current_command->args != NULL)
		{
			i = 0;
			while (current_command->args[i] != NULL)
			{
				printf("Argument %d: %s (address: %p)\n", i, current_command->args[i], &current_command->args[i]);
				i++;
			}
				printf("\n");
		}
		current_command = current_command->next;
	}
}
