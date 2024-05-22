/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:31:42 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 17:02:49 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	store_command(t_data *data, t_cmd **cmd, t_token **token, int *is_first)
{
	if (*is_first && (*token) != NULL && (*token)->data != NULL)
	{
		*is_first = 0;
		(*cmd)->com = detect_cmd_type((*token));
	}
	if ((*token)->type != PIPE)
	{
		if ((*token)->type == REDIR)
			handle_redirections(&(*token), data, (*cmd));
		else
			add_token_to_command(data, (*cmd), (*token));
	}
	else
	{
		*is_first = 1;
		add_command_to_list(&(data->cmd_lst), (*cmd));
		(*cmd) = cmd_init();
	}
	*token = (*token)->next;
}

void	store_token(t_cmd *command, t_token *token)
{
	char	**new_args;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
