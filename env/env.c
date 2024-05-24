/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 16:08:34 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

/**
 * @brief Store all the env variables
 * 
 * @param data whole data
 * @param environ array of string that hold env variables
 * @return void
 */
void	ft_store_env(t_data *data, char **environ)
{
	char		**env_json;
	t_env		*env;

	if (!environ)
		return ;
	while (*environ)
	{
		env_json = (char **)ft_calloc(2, sizeof(char *));
		env = (t_env *)ft_calloc(1, sizeof(t_env));
		if (!env_json)
			critical_err(strerror(errno));
		ft_to_json(env_json, *environ++);
		env->key = env_json[0];
		env->value = env_json[1];
		ft_lstadd_back(&data->env_lst, ft_lstnew(env));
		free(env_json);
	}
}
