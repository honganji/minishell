/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:49:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/22 18:37:03 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	detect_input(int *is_input, t_token *tokens, t_redir *redir)
{
	*is_input = 0;
	if (ft_strncmp(tokens->data, ">>", 2) == 0)
		redir->is_single = 0;
	else
		redir->is_single = 1;
}

void	handle_redirections(
			t_token **tokens, t_data *data, t_cmd *current_command)
{
	t_redir	*redir;
	int		is_input;

	(void)data;
	redir = malloc(sizeof(t_redir));
	is_input = 1;
	if (redir == NULL)
		return ;
	if (ft_strchr((*tokens)->data, '>'))
		detect_input(&is_input, *tokens, redir);
	else
	{
		if (ft_strncmp((*tokens)->data, "<<", 2) == 0)
			redir->is_single = 0;
		else
			redir->is_single = 1;
	}
	(*tokens) = (*tokens)->next;
	redir->file_name = (*tokens)->data;
	if (is_input)
		current_command->input = *redir;
	else
		current_command->output = *redir;
}
