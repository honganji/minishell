/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:50:38 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/23 16:06:51 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief helper function to handle no args
 * 
 * @param data data
 * @param arg string to export
 * @return void
 */
void	handle_no_args(t_data *data, char *arg)
{
	t_list	*tmp;

	tmp = data->env_lst;
	arg = join_to_export(arg, tmp);
	ft_input_data(data, arg, 0);
}

/**
 * @brief helper function to handle args
 * 
 * @param env_arr array of key and value
 * @param env_json env list of key and value
 * @return void
 * 
 */
void	handle_args(char *arg, char **env_arr, t_env *env_json)
{
	ft_to_json(env_arr, arg);
	env_json->key = env_arr[0];
	env_json->value = env_arr[1];
}

/**
 * @brief checks and updates env variable or creates a new one
 *
 * @param data data
 * @param env_json env list of key and value
 * @param env_arr array of arguments (key and value)
 * @return void
 */
void	update_env_var(t_data *data, t_env *env_json, char **env_arr)
{
	t_list	*targ_lst;

	if (ft_isdigit(*env_json->key))
	{
		syntax_err(data, "export: not a valid identifier: ", env_json->key, 1);
		free(env_arr);
		free(env_json);
		ft_input_data(data, "", 0);
		return ;
	}
	targ_lst = ft_find_ele(data, env_json->key);
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
