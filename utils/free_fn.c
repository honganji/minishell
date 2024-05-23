/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:59:57 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 15:07:04 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

// static void	free_redir(t_redir *redir)
// {
// 	if (redir->file_name)
// 		free(redir->file_name);
// 	free(redir);
// }

void	free_env_lst(t_data *data)
{
	t_list	*node;

	node = data->env_lst;
	while (node)
	{
		free(((t_env *)node->content)->key);
		free(((t_env *)node->content)->value);
		free(node->content);
		node = node->next;
	}
}

void	free_cmd_lst(t_data *data)
{
	t_list	*node;
	t_list	*tmp;

	node = data->cmd_lst;
	while (node)
	{
		tmp = node;
		free_arr(((t_cmd *)node->content)->args);
		// free_redir(&((t_cmd *)node->content)->input);
		// free_redir(&((t_cmd *)node->content)->output);
		free(tmp);
		node = node->next;
	}
}

void	free_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		tmp = token;
		// if (tmp->data)
		// 	free(tmp->data);
		free(tmp);
		token = token->next;
	}
	// free(token);
}
