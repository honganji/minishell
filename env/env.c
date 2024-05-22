/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuji <yuji@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/22 08:35:25 by yuji             ###   ########.fr       */
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

	if (!environ)
		return ;
	while (*environ)
	{
		env_json = (char **)ft_calloc(1, sizeof(char *));
		if (!env_json)
			critical_err(strerror(errno));
		ft_to_json(env_json, *environ++);
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
	}
}
