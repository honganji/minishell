/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/04 13:39:16 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// For export command
void	ft_export(t_data *data, char *str)
{
	char	**arr;
	t_env	*env_json;
	t_list	*targ_lst;
	int		i;

	env_json = ft_calloc(1, sizeof(t_env));
	arr = ft_split(str, '=');
	i = 0;
	while (arr[1][i] != ' ' && arr[1][i])
		i++;
	arr[1][i] = '\0';
	env_json->key = arr[0];
	env_json->value = arr[1];
	targ_lst = ft_find_ele(data, env_json->key);
	if (targ_lst)
	{
		(*(t_env *)targ_lst->content).key = env_json->key;
		(*(t_env *)targ_lst->content).value = env_json->value;
	}
	else
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
}

// For unset command
void	ft_unset(t_data *data, char *str)
{
	char	*key;
	t_list	*pre_lst;
	t_list	*tmp_lst;

	pre_lst = NULL;
	tmp_lst = data->env_lst;
	while (tmp_lst)
	{
		key = (*(t_env *)((tmp_lst)->content)).key;
		if (!ft_strncmp(key, str, ft_strlen(str)))
			ft_del_node(data, &tmp_lst, pre_lst);
		pre_lst = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
}
