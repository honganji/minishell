/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:31:42 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/06/06 18:13:49 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	store_command(t_data *data, t_cmd **cmd, t_token **token, int *is_first)
{
	if (*is_first && (*token) != NULL && (*token)->data != NULL)
	{
		if ((*token)->data[0] == '$' && (ft_getenv2(data,
					&((*token)->data[1])) == NULL))
		{
			syntax_err(data, "command not found", (*token)->data, 127);
			return (1);
		}
		*is_first = 0;
		(*cmd)->com = detect_cmd_type((*token));
	}
	if ((*token)->type != PIPE)
		check_for_redir(data, &(*token), &(*cmd));
	else
	{
		*is_first = 1;
		add_command_to_list(&(data->cmd_lst), (*cmd));
		(*cmd) = cmd_init();
	}
	*token = (*token)->next;
	return (0);
}

void	check_for_redir(t_data *data, t_token **token, t_cmd **cmd)
{
	if ((*token)->type == REDIR)
		handle_redirections(&(*token), data, *cmd);
	else
		add_token_to_command(data, *cmd, (*token));
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
