/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/03 21:20:32 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_export(t_data **data, char *str)
{
	char	**arr;
	t_env	*env_json;

	env_json = ft_calloc(1, sizeof(t_env));
	arr = ft_split(str, '=');
	env_json->key = arr[0];
	env_json->value = arr[1];
	ft_lstadd_back(&(*data)->env_lst, ft_lstnew(env_json));
}
