/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:24 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 19:11:27 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42-c-library/library.h"
#include "execution.h"

static int	count_env(void)
{
	extern char	**environ;
	char		**env_name;
	int			count;

	count = 0;
	env_name = environ;
	while (*env_name++)
		count++;
	return (count);
}

// TODO Deal with when the env variables doesn't exist
void	store_env(t_data *data)
{
	extern char	**environ;
	char		**env_name;
	char		**env_json;
	int			i;

	env_name = environ;
	env_json = (char **)ft_calloc(1, sizeof(char *));
	data->arr = ft_calloc(count_env(), sizeof(t_env));
	i = 0;
	while (*env_name)
	{
		ft_to_json(env_json, *env_name++);
		data->arr[i].key = env_json[0];
		data->arr[i].value = env_json[1];
		ft_lstadd_back(&data->env_lst, ft_lstnew(&data->arr[i++]));
	}
	free(env_json);
}
