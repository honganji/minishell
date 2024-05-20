/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:46:58 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/20 13:14:46 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/init.h"

t_token	*token_init(void)
{
	t_token	*token;
	int	i;

	i = 0;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = 0;
	token->data = NULL;
	token->next = NULL;
	return (token);
}

t_cmd *cmd_init(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->com = 0;
	cmd->input.file_name = NULL;
	cmd->output.file_name = NULL;
	return (cmd);
}

void	initialize(t_data *data, char **env)
{
	data->stdin_fd = dup(STDIN_FILENO);
	data->exit_code = 0;

	// Set the valuables
	set_val(data, env);

	// Set signal for ctrl-c and ctrl-backslash
	set_signal_fn();
}
