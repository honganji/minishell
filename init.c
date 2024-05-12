/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:46:58 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/12 18:29:44 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/minishell.h"

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
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_cmd_list	*cmd_list_init(void)
{
	t_cmd_list	*list;

	list = malloc(sizeof(t_cmd_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	int		i;

	i = 0;
	env = malloc(sizeof(t_env));
	env->key = ft_strchr(envp[i], '=') + 1;
	env->value = ft_strchr(envp[i], '=') + 1;
	env->next = NULL;
	tmp = env;
	i++;
	while (envp[i])
	{
		tmp->next = malloc(sizeof(t_env));
		tmp = tmp->next;
		tmp->key = ft_strchr(envp[i], '=') + 1;
		tmp->value = ft_strchr(envp[i], '=') + 1;
		tmp->next = NULL;
		i++;
	}
	return (env);
}
