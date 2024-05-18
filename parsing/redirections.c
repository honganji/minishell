/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:49:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/16 18:07:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_redirections(t_token *tokens, t_data *data)
{
	t_redir	*redir;
	t_token	*current_token;

	current_token = tokens;
	redir = malloc(sizeof(t_redir));
	if (redir == NULL)
		return ;
	if (ft_strncmp(current_token->data, ">>", 2) == 0)
		redir->is_single = 0;
	else if (ft_strncmp(current_token->data, "<<", 2) == 0)
		redir->is_single = 0;
	else if (ft_strncmp(current_token->data, "<", 1) == 0)
		redir->is_single = 1;
	else if (ft_strncmp(current_token->data, ">", 1) == 0)
		redir->is_single = 1;
	redir->file_name = current_token->next->data;
	// printf("token type: %d\n", current_token->type);		//!DEBUG
	// printf("file name: %s\n", redir->file_name);
	// printf("is_single: %d\n", redir->is_single);
}
