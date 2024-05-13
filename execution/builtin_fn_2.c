/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/13 19:04:37 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// For export command
void	ft_export(t_data *data, char *str)
{
	char	**env_arr;
	t_env	*env_json;
	t_list	*targ_lst;

	env_arr = (char **)ft_calloc(1, sizeof(char *));
	env_json = (t_env *)malloc(1 * sizeof(t_env));
	ft_to_json(env_arr, str);
	env_json->key = env_arr[0];
	env_json->value = env_arr[1];
	targ_lst = ft_find_ele(data, env_arr[0]);
	if (targ_lst)
	{
		free((*(t_env *)targ_lst->content).key);
		free((*(t_env *)targ_lst->content).value);
		(*(t_env *)targ_lst->content).key = env_json->key;
		(*(t_env *)targ_lst->content).value = env_json->value;
		free(env_json);
	}
	else
		ft_lstadd_back(&data->env_lst, ft_lstnew(env_json));
	free(env_arr);
	ft_input_data("", 0);
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
			ft_del_node(data, tmp_lst, pre_lst);
		pre_lst = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	ft_input_data("", 0);
}
