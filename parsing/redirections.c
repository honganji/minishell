/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:49:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/21 09:41:17 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_redirections(t_token *tokens, t_data *data, t_cmd *current_command)
{
	t_redir	*redir;
	t_token	*current_token;
	int		is_input;

	(void)data;
	current_token = tokens;
	redir = malloc(sizeof(t_redir));
	is_input = 1;
	if (redir == NULL)
		return ;
	if (ft_strchr(current_token->data, '>'))
	{
		is_input = 0;
		if (ft_strncmp(current_token->data, ">", 1) == 0)
			redir->is_single = 1;
		else if (ft_strncmp(current_token->data, ">>", 2) == 0)
			redir->is_single = 0;
	}
	else
	{
		if (ft_strncmp(current_token->data, "<", 1) == 0)
			redir->is_single = 1;
		else if (ft_strncmp(current_token->data, "<<", 2) == 0)
			redir->is_single = 0;
	}
	redir->file_name = current_token->next->data;
	if (is_input)
		current_command->input = *redir;
	else
		current_command->output = *redir;
	// printf("token type: %d\n", current_token->type);		//!DEBUG
	// printf("file name: %s\n", redir->file_name);
	// printf("is_single: %d\n", redir->is_single);
}
