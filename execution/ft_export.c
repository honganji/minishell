/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/23 16:12:51 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/**
 * @brief Join two strings safely
 *
 * @param str string
 * @param append string to append
 * @return char*
 *
 */
char	*safe_strjoin(char *str, char *append)
{
	str = ft_free_strjoin(str, append);
	if (!str)
		critical_err(strerror(errno));
	return (str);
}
/**
 * @brief Join env variable list into a string
 *
 * @param str string
 * @param env_list env variable list
 * @return char*
 *
 */
char	*join_to_export(char *str, t_list *env_list)
{
	while (env_list)
	{
		str = safe_strjoin(str, "declare -x");
		str = safe_strjoin(str, (*(t_env *)(env_list->content)).key);
		str = safe_strjoin(str, "=");
		str = safe_strjoin(str, "\"");
		str = safe_strjoin(str, (*(t_env *)(env_list->content)).value);
		str = safe_strjoin(str, "\"");
		str = safe_strjoin(str, "\n");
		env_list = env_list->next;
	}
	return (str);
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
	t_list	*targ_lst;
	char	*arg;
	t_list	*tmp;

	arg = ft_strdup("");
	if (!((t_cmd *)data->cmd_lst->content)->args[1])
	{
		tmp = data->env_lst;
		arg = join_to_export(arg, tmp);
		ft_input_data(data, arg, 0);
		return ;
	}
	arg = ((t_cmd *)data->cmd_lst->content)->args[1];
	if (!ft_strchr(arg, '='))
	{
		ft_input_data(data, "", 0);
		return ;
	}
	env_arr = (char **)ft_calloc(2, sizeof(char *));
	env_json = (t_env *)malloc(sizeof(t_env));
	if (!env_arr || !env_json)
		critical_err(strerror(errno));
	ft_to_json(env_arr, arg);
	env_json->key = env_arr[0];
	if (ft_isdigit(*env_json->key))
	{
		syntax_err(data, "export: not a valid identifier: ", env_json->key, 1);
		free(env_arr);
		free(env_json);
		ft_input_data(data, "", 0);
		return ;
	}
	env_json->value = env_arr[1];
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
