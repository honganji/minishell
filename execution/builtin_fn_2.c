/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/21 17:58:19 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief export value into env linked list
 * 
 * @param data data
 * @param str string include key and value connected with '='
 * @return void
 */
void	ft_export(t_data *data)
{
	char	**env_arr;
	t_env	*env_json;
	t_list	*targ_lst;

	env_arr = (char **)ft_calloc(1, sizeof(char *));
	env_json = (t_env *)malloc(1 * sizeof(t_env));
	if (!env_arr || !env_json)
		critical_err(strerror(errno));
	if (!((t_cmd *)data->cmd_lst->content)->args[1])
		return ;
	ft_to_json(env_arr, ((t_cmd *)data->cmd_lst->content)->args[1]);				//TODO fix endless loop and implement check for invalid key
	env_json->key = env_arr[0];
	if (ft_isdigit(*env_arr[0]))
	{
		syntax_err(data, "export: not a valid identifier: ", env_arr[0], 1);
		free(env_arr);
		free(env_json);
		return ;
	}
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
	ft_input_data(data, "", 0);
	data->exit_code = 0;
}

/**
 * @brief export value into env linked list
 * 
 * @param data data
 * @param str string include key and value connected with '='
 * @return void
 */
void	ft_unset(t_data *data)
{
	char	*key;
	t_list	*pre_lst;
	t_list	*tmp_lst;
	char	*str;

	pre_lst = NULL;
	tmp_lst = data->env_lst;
	str = ((t_cmd *)data->cmd_lst->content)->args[1];
	while (tmp_lst)
	{
		key = (*(t_env *)((tmp_lst)->content)).key;
		if (!ft_strncmp(key, str, ft_strlen(str)))
			ft_del_node(data, tmp_lst, pre_lst);
		pre_lst = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	ft_input_data(data, "", 0);
	data->exit_code = 0;
}
