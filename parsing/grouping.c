/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:33 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/20 14:02:00 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	parse_commands(t_token *tokens, t_data *data)
// {
// 	t_cmd	*current_command;
// 	t_token	*current_token;

// 	current_command = cmd_init();
// 	current_token = tokens;
// 	data->cmd_lst = NULL;
// 	while (current_token != NULL)
// 	{
// 		if (current_token->type != PIPE)
// 		{
// 			if (current_token->type == REDIR)								//TODO handle escaped chars
// 				handle_redirections(current_token, data);
// 			else
// 				add_token_to_command(current_command, current_token);
// 				printf("before assignin com type\n");
// 				if (current_token == NULL)
// 					break ;
// 				current_command->com = detect_cmd_type(current_token);
// 				printf("token data: %s\n", current_token->data);
// 				printf("com type: %d\n", current_command->com);
// 				printf("after assignin com type\n");
// 		}
// 		else
// 		{
// 			add_command_to_list(&(data->cmd_lst), current_command);
// 			current_command = cmd_init();
// 		}
// 		current_token = current_token->next;
// 	}
// 	add_command_to_list(&(data->cmd_lst), current_command);
// 	print_commands(data->cmd_lst);
// }

// t_com	detect_cmd_type(t_token *token)
// {
// 	if (ft_strncmp(token->data, "echo", 5) == 0)
// 		return (ECHO);
// 	else if (ft_strncmp(token->data, "cd", 3) == 0)
// 		return (CD);
// 	else if (ft_strncmp(token->data, "pwd", 4) == 0)
// 		return (PWD);
// 	else if (ft_strncmp(token->data, "export", 7) == 0)
// 		return (EXPORT);
// 	else if (ft_strncmp(token->data, "unset", 6) == 0)
// 		return (UNSET);
// 	else if (ft_strncmp(token->data, "env", 4) == 0)
// 		return (ENV);
// 	else if (ft_strncmp(token->data, "exit", 5) == 0)
// 		return (EXIT);
// 	else
// 		return (ETC);
// }

// void	add_token_to_command(t_cmd *command, t_token *token)
// {
// 	int		i;
// 	int		j;
// 	char	**new_args;

// 	i = 0;
// 	j = 0;
// 	if (command->args == NULL)
// 	{
// 		command->args = malloc(sizeof(char *) * 2);
// 		if (command->args == NULL)
// 			return ;
// 		command->args[0] = token->data;
// 		command->args[1] = NULL;
// 	}
// 	else
// 	{
// 		while (command->args[i] != NULL)
// 			i++;
// 		new_args = malloc(sizeof(char *) * (i + 2));
// 		if (new_args == NULL)
// 			return ;
// 		while (j < i)
// 		{
// 			new_args[j] = command->args[j];
// 			j++;
// 		}
// 		new_args[i] = token->data;
// 		new_args[i + 1] = NULL;
// 		free(command->args);
// 		command->args = new_args;
// 	}
// }

// void	add_command_to_list(t_list **head, t_cmd *new_command)
// {
// 	t_list	*new_node;
// 	t_list	*current;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return ;
// 	new_node->content = new_command;
// 	new_node->next = NULL;
// 	if (*head == NULL)
// 		*head = new_node;
// 	else
// 	{
// 		current = *head;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = new_node;
// 	}
// }

// void	print_commands(t_list *command_list)
// {
// 	t_list	*current_node;
// 	int		i;
// 	t_cmd	*current_command;

// 	current_node = command_list;
// 	while (current_node != NULL)
// 	{
// 		current_command = (t_cmd *)current_node->content;
// 		printf("Command:\n");
// 		if (current_command->args != NULL)
// 		{
// 			i = 0;
// 			while (current_command->args[i] != NULL)
// 			{
// 				printf("Argument %d: %s\n", i, current_command->args[i]);
// 				i++;
// 			}
// 			printf("\n");
// 		}
// 		current_node = current_node->next;
// 	}
// }

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
			if (current_token->type == REDIR)
				handle_redirections(current_token, data);
			else
				add_token_to_command(current_command, current_token);
			if (current_token->data != NULL)
                current_command->com = detect_cmd_type(current_token);
		}
		else
		{
			add_command_to_list(&(data->cmd_lst), current_command);
			current_command = cmd_init();
		}
		current_token = current_token->next;
	}
	add_command_to_list(&(data->cmd_lst), current_command);
	// print_commands(data->cmd_lst);
}

t_com	detect_cmd_type(t_token *token)
{
	if (!token || !token->data)
		return (ETC);
	if (ft_strncmp(token->data, "echo", 5) == 0)
		return (ECHO);
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
