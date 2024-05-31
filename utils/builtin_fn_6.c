/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:15:55 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/31 16:27:02 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

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

char	*remove_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (!str[i])
			break ;
		if (str[i] == '\'' || str[i] == '\"')
		{
			j = i;
			while (str[j])
			{
				if (!str[j + 1])
					str[j] = '\0';
				else
					str[j] = str[j + 1];
				j++;
			}
			j = 0;
		}
		else
			i++;
	}
	new_str = ft_strdup(str);
	free(str);
	return (new_str);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (0);
		if (*str++ == '=')
			return (1);
	}
	return (1);
}

int	check_minus(char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (0);
		if (*str++ == '=')
			return (1);
	}
	return (1);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}
