/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:49:24 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/21 10:22:02 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_redirections(t_token **tokens, t_data *data, t_cmd *current_command)
{
	t_redir	*redir;
	int		is_input;

	(void)data;
	redir = malloc(sizeof(t_redir));
	is_input = 1;
	if (redir == NULL)
		return ;
	if (ft_strchr((*tokens)->data, '>'))
	{
		is_input = 0;
		if (ft_strncmp((*tokens)->data, ">>", 2) == 0)
			redir->is_single = 0;
		else
			redir->is_single = 1;
	}
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
	// printf("token type: %d\n", (*tokens)->type);		//!DEBUG
	// printf("file name: %s\n", redir->file_name);
	// printf("is_single: %d\n", redir->is_single);
}
