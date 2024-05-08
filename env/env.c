/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/08 20:06:47 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	ft_store_env(t_data *data, char **environ)
{
	char		**env_json;
	int			i;

	i = 0;
	if (!environ)
		return ;
	while (*environ)
	{
		env_json = (char **)ft_calloc(1, sizeof(char *));
		ft_to_json(env_json, *environ++);
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
	}
}
