/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:59:57 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 12:13:20 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static void	free_redir(void *content)
{
	t_redir	input;
	t_redir	output;

	input = ((t_cmd *)content)->input;
	output = ((t_cmd *)content)->output;
	if (input.file_name)
		free(input.file_name);
	if (output.file_name)
		free(output.file_name);
}

void	free_env_lst(t_data *data)
{
	t_list	*node;
	t_list	*tmp;

	node = data->env_lst;
	while (node)
	{
		tmp = node;
		free(((t_env *)node->content)->key);
		free(((t_env *)node->content)->value);
		free(node->content);
		node = node->next;
		free(tmp);
	}
	// free(data->env_lst);
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
		free_redir(node->content);
		free(node->content);
		node = node->next;
		free(tmp);
	}
}

void	free_token(t_token *token)
{
	t_token	*node;
	t_token	*tmp;

	node = token;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	free_data(t_data *data)
{
	free_env_lst(data);
	free_cmd_lst(data);
	free(data);
	data = NULL;
}
