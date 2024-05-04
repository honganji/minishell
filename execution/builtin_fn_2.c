/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 09:29:25 by ytoshihi         ###   ########.fr       */
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

void	ft_unset(t_data **data, char *str)
{
	char	*key;
	t_list	*pre_lst;
	t_list	*tmp_lst;

	pre_lst = NULL;
	tmp_lst = (*data)->env_lst;
	while (tmp_lst)
	{
		key = (*(t_env *)((tmp_lst)->content)).key;
		if (!ft_strncmp(key, str, ft_strlen(str)))
			ft_del_node(data, &tmp_lst, pre_lst);
		pre_lst = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	printf("There is no variable named %s...\n", str);
}
