/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/31 15:06:02 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_commands(t_token *tokens, t_data *data)
{
	t_cmd	*current_command;
	t_token	*current_token;
	int		is_first;

	current_command = cmd_init();
	current_token = tokens;
	data->cmd_lst = NULL;
	is_first = 1;
	while (current_token != NULL)
		store_command(data, &current_command, &current_token, &is_first);
	add_command_to_list(&(data->cmd_lst), current_command);
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
	// t_list	*new_node;
	// t_list	*current;

	// new_node = malloc(sizeof(t_list));
	// if (!new_node)
	// 	return ;
	// new_node->content = new_command;
	// new_node->next = NULL;
	// if (*head == NULL)
	// 	*head = new_node;
	// else
	// {
	// 	current = *head;
	// 	while (current->next != NULL)
	// 		current = current->next;
	// 	current->next = new_node;
	// }
	ft_lstadd_back(head, ft_lstnew(new_command));
}

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
