/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:46:58 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/07 13:33:12 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
