/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:46:58 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/15 16:33:56 by adprzyby         ###   ########.fr       */
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

t_exe *cmd_init(void)
{
	t_exe	*cmd;

	cmd = malloc(sizeof(t_exe));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->input = NULL;
	cmd->output = NULL;
	return (cmd);
}
