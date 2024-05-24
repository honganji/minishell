/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:22:18 by ytoshihi          #+#    #+#             */
/*   Updated: 2024/05/24 20:05:04 by ytoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	join_str(char **str, t_list *tmp)
{
	(*str) = ft_free_strjoin((*str), (*(t_env *)(tmp->content)).key);
	if (!(*str))
		critical_err(strerror(errno));
	(*str) = ft_free_strjoin((*str), "=");
	if (!(*str))
		critical_err(strerror(errno));
	(*str) = ft_free_strjoin((*str), (*(t_env *)(tmp->content)).value);
	if (!(*str))
		critical_err(strerror(errno));
	(*str) = ft_free_strjoin((*str), "\n");
	if (!(*str))
		critical_err(strerror(errno));
}

static void	env_err(t_data *data, char *arg)
{
	set_exit_code(data, 127);
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("No such file or directory", 2);
	ft_putstr_fd("\n", 2);
}

/**
 * @brief get all the env variable and send them to input parameter
 * 
 * Read all the node of a env variable list and combine using ft_free_strjoin
 * @param data data
 * @return void
 */
void	ft_env(t_list *env_lst, t_data *data, char *arg)
{
	t_list	*tmp;
	char	*str;

	tmp = env_lst;
	str = ft_strdup("");
	if (!str)
		critical_err(strerror(errno));
	if (arg)
	{
		env_err(data, arg);
		ft_input_data(data, "", 0);
		free(str);
		return ;
	}
	while (tmp)
	{
		join_str(&str, tmp);
		tmp = tmp->next;
	}
	ft_input_data(data, str, 0);
	return (free(str), set_exit_code(data, 0));
}
