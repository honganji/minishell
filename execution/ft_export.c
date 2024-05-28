/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 13:40:12 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	add_value(t_data *data, t_env *env_json)
{
	t_list	*targ_lst;

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
}

static int	check_equal(t_data *data, char *arg)
{
	if (!ft_strchr(arg, '='))
	{
		ft_input_data(data, "", 0);
		return (1);
	}
	return (0);
}

static int	check_if_digit(t_data *data, t_env *env_json, char **env_arr)
{
	if (ft_isdigit(*env_json->key))
	{
		syntax_err(data, "export: not a valid identifier: ", env_json->key, 1);
		free(env_arr);
		free(env_json);
		ft_input_data(data, "", 0);
		return (1);
	}
	return (0);
}

static int	check_no_arg(t_data *data)
{
	char	*arg;
	t_list	*tmp;

	arg = ft_strdup("");
	if (!((t_cmd *)data->cmd_lst->content)->args[1])
	{
		tmp = data->env_lst;
		arg = join_to_export(arg, tmp);
		ft_input_data(data, arg, 0);
		return (free(arg), 1);
	}
	return (free(arg), 0);
}

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
	char	*arg;

	if (check_no_arg(data))
		return ;
	arg = ((t_cmd *)data->cmd_lst->content)->args[1];
	if (check_equal(data, arg))
		return ;
	env_arr = (char **)ft_calloc(2, sizeof(char *));
	env_json = (t_env *)malloc(sizeof(t_env));
	if (!env_arr || !env_json)
		critical_err(strerror(errno));
	ft_to_json(env_arr, arg);
	env_json->key = env_arr[0];
	if (check_if_digit(data, env_json, env_arr))
		return ;
	env_json->value = env_arr[1];
	add_value(data, env_json);
	free(env_arr);
	ft_input_data(data, "", 0);
	data->exit_code = 0;
}
