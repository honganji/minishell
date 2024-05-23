/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 17:12:35 by adprzyby         ###   ########.fr       */
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
	char	*arg;
	char	**env_arr;
	t_env	*env_json;

	arg = ft_strdup("");
	if (!((t_cmd *)data->cmd_lst->content)->args[1])
	{
		handle_no_args(data, arg);
		return ;
	}
	env_arr = (char **)ft_calloc(2, sizeof(char *));
	env_json = (t_env *)malloc(sizeof(t_env));
	if (!env_arr || !env_json)
		critical_err(strerror(errno));
	arg = ((t_cmd *)data->cmd_lst->content)->args[1];
	if (!ft_strchr(arg, '='))
	{
		ft_input_data(data, "", 0);
		return ;
	}
	handle_args(arg, env_arr, env_json);
	update_env_var(data, env_json, env_arr);
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
