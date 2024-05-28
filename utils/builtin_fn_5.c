/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:14:31 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/28 13:40:55 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

/**
 * @brief Join two strings safely
 *
 * @param str string
 * @param append string to append
 * @return char*
 *
 */
static char	*safe_strjoin(char *str, char *append)
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
char	*join_to_env(char *str, t_list *env_list)
{
	while (env_list)
	{
		str = safe_strjoin(str, (*(t_env *)(env_list->content)).key);
		str = safe_strjoin(str, "=");
		str = safe_strjoin(str, (*(t_env *)(env_list->content)).value);
		str = safe_strjoin(str, "\n");
		env_list = env_list->next;
	}
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
		str = safe_strjoin(str, "declare -x ");
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
