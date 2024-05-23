/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fn_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:05 by adprzyby          #+#    #+#             */
/*   Updated: 2024/05/23 14:54:29 by adprzyby         ###   ########.fr       */
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
